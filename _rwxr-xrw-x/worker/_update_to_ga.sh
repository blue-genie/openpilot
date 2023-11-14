set +x

TARGET_BRANCH="f150"

git checkout ${SOURCE_BRANCH}
git branch -D ${TARGET_BRANCH}
git branch ${TARGET_BRANCH}
git checkout ${TARGET_BRANCH}
git push --set-upstream origin ${TARGET_BRANCH} --force