set +x

echo $REPO
echo $SOURCE_BRANCH
echo $TARGET_BRANCH

git fetch $REPO

git branch -D $TARGET_BRANCH
git checkout -b $TARGET_BRANCH $SOURCE_BRANCH