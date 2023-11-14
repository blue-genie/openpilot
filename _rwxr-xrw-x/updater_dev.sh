set -x
export REPO="commaai"
S_BRANCH="$REPO/master-ci"
I_BRANCH="master-ci"
T_BRANCH="f150-dev"


export SOURCE_BRANCH=$S_BRANCH
export TARGET_BRANCH=$I_BRANCH
sh worker/_update_local.sh

export SOURCE_BRANCH=$I_BRANCH
export TARGET_BRANCH=$T_BRANCH
sh worker/_update_branch.sh
