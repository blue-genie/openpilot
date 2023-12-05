#!/usr/bin/env python3
import logging
import os
import stat
import time
import traceback
from pathlib import Path
from urllib.request import urlopen

import requests

import selfdrive.sentry as sentry
from common.spinner import Spinner
from openpilot.selfdrive.mapd_manager import COMMON_DIR, MAPD_PATH, VERSION_PATH, MAPD_BIN_DIR

VERSION = 'v1.7.2'
URL = f"https://github.com/pfeiferj/openpilot-mapd/releases/download/{VERSION}/mapd"


class MapdInstallManager:
  def __init__(self, spinner_ref):
    self._spinner = spinner_ref

  def download(self):
    self._create_directory()
    self._download_file()
    self._store_version()

  def check_and_download(self):
    if self.download_needed():
      self.download()

  def download_needed(self):
    return not self._is_exists() or self._needs_update()

  @staticmethod
  def _create_directory():
    if not os.path.exists(COMMON_DIR):
      os.makedirs(COMMON_DIR)
    if not os.path.exists(MAPD_BIN_DIR):
      os.makedirs(MAPD_BIN_DIR)

  @staticmethod
  def _safe_write_and_set_executable(file_path, content):
    with open(file_path, 'wb') as output:
      output.write(content)
      output.flush()
      os.fsync(output.fileno())
    current_permissions = stat.S_IMODE(os.lstat(file_path).st_mode)
    os.chmod(file_path, current_permissions | stat.S_IEXEC)

  def _download_file(self, num_retries=5):
    temp_file = Path(MAPD_PATH + ".tmp")
    for cnt in range(num_retries):
      try:
        response = requests.get(URL, stream=True)
        response.raise_for_status()
        self._safe_write_and_set_executable(temp_file, response.content)

        # No exceptions encountered. Safe to replace original file.
        temp_file.replace(MAPD_PATH)
        return
      except requests.exceptions.RequestException:
        self._spinner.update(f"IncompleteRead caught. Retrying download... [{cnt}]")
        time.sleep(0.5)

    # Delete temp file if the process was not successful.
    if temp_file.exists():
      temp_file.unlink()
    logging.error("Failed to download file after all retries")

  @staticmethod
  def _store_version():
    with open(VERSION_PATH, 'w') as output:
      output.write(VERSION)
      os.fsync(output.fileno())

  @staticmethod
  def _is_exists():
    return os.path.exists(MAPD_PATH) and os.path.exists(VERSION_PATH)

  @staticmethod
  def _needs_update():
    with open(VERSION_PATH) as f:
      return f.read() != VERSION

  def wait_for_internet_connection(self, return_on_failure=False):
    for retries in range(16):
      try:
        if self._spinner:
          self._spinner.update(f"Waiting for internet connection... [{retries}]")
          time.sleep(0.5)
        _ = urlopen('https://www.google.com/', timeout=10)
        return True
      except Exception as e:
        print(f'Wait for internet failed: {e}')
        if return_on_failure and retries == 15:
          return False
        time.sleep(2)  # Wait for 2 seconds before retrying


if __name__ == "__main__":
  spinner = Spinner()
  spinner.update("Checking if mapd is installed and valid")
  time.sleep(0.1)
  try:
    install_manager = MapdInstallManager(spinner)
    if not install_manager.download_needed():
      spinner.update("Mapd is good!")
      time.sleep(0.1)
      exit(0)

    if install_manager.wait_for_internet_connection(return_on_failure=True):
      spinner.update(f"Downloading pfeiferj's mapd [{VERSION}]")
      time.sleep(0.1)
      install_manager.check_and_download()
    spinner.close()

  except Exception:
    for i in range(6):
      spinner.update(f"Failed to download OSM maps won't work until properly downloaded!"
                     f"Try again manually rebooting. "
                     f"Boot will continue in {5 - i}s...")
      time.sleep(1)

    sentry.init(sentry.SentryProject.SELFDRIVE)
    traceback.print_exc()
    sentry.capture_exception()

