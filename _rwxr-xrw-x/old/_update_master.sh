set -x
TARGET_BRANCH="master"

git fetch commaai
# git checkout $TARGET_BRANCH
# git branch -D master
# git checkout -b master commaai/master
git checkout master
# git merge commaai/$TARGET_BRANCH
git pull --tags commaai $TARGET_BRANCH
git push
# git push -u origin --force

# git branch -D $TARGET_BRANCH
# git checkout -b $TARGET_BRANCH commaai/$TARGET_BRANCH
# git push -u origin --force