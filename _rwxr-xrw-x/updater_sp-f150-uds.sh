#!/bin/bash

set -x
export REPO="sunny"
S_BRANCH="$REPO/dev-c3"
I_BRANCH="sp-dev-c3"
T_BRANCH="sp-f150-uds"

export SOURCE_BRANCH=$S_BRANCH
export TARGET_BRANCH=$I_BRANCH
sh worker/_update_local.sh

export SOURCE_BRANCH=$I_BRANCH
export TARGET_BRANCH=$T_BRANCH
sh worker/_update_branch.sh
