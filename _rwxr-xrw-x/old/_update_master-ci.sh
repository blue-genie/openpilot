set -x
TARGET_BRANCH="master-ci"


git fetch commaai

git branch -D master
git checkout -b master commaai/master
# git merge commaai/$TARGET_BRANCH
# git push -u origin --force

git branch -D $TARGET_BRANCH
git checkout -b $TARGET_BRANCH commaai/$TARGET_BRANCH
# git push -u origin --force