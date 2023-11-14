set -x

# SOURCE_BRANCH="master-ci"
SOURCE_BRANCH="f150"
TARGET_BRANCH="f150-dev"
git checkout ${SOURCE_BRANCH}
git branch -D ${TARGET_BRANCH}
# git push origin --delete ${TARGET_BRANCH}
git branch ${TARGET_BRANCH}
git checkout ${TARGET_BRANCH}
git cherry-pick df1e3af8d2e1f55a74163d1112f9941bdc2a77f4
git cherry-pick ba27e55360fe1b1a166577ff527455dda44ab014
git cherry-pick 5a6d48977bbbd1050f2bd25f839e4c37dae262ea
# git cherry-pick 0cfbea83b250e89bea0e50aa1185d16ac7b99cfb
# git cherry-pick bacde139e4c2c3837700731835b456f705824a26
# git cherry-pick fd99a463ab18d6a7120179b5c420a00694049a7a
git push --set-upstream origin ${TARGET_BRANCH} --force
