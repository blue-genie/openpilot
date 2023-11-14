#!/bin/bash

set -x
export REPO="sunny"
S_BRANCH="$REPO/master"
I_BRANCH="sp-master"

export SOURCE_BRANCH=$S_BRANCH
export TARGET_BRANCH=$I_BRANCH
sh worker/_update_local.sh
