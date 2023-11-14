set -x
SOURCE_BRANCH="sunny/dev-c3"
INTERIM_BRANCH="sp-dev-c3"
TARGET_BRANCH="sp-f150-dev"


git fetch sunny

git branch -D $TARGET_BRANCH
git checkout -b $TARGET_BRANCH $INTERIM_BRANCH

git checkout ${INTERIM_BRANCH}
git branch -D ${TARGET_BRANCH}

git branch ${TARGET_BRANCH}
git checkout ${TARGET_BRANCH}

# F-150 14th Gen ONLY
git cherry-pick ba27e55360fe1b1a166577ff527455dda44ab014

# Ford: change LatCtlPrecision_D_Rq to comfortable
git cherry-pick df1e3af8d2e1f55a74163d1112f9941bdc2a77f4

# # Lead ACC Data
# git cherry-pick 5a6d48977bbbd1050f2bd25f839e4c37dae262ea

git push --set-upstream origin ${TARGET_BRANCH} --force
