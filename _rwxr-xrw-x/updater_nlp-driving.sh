set -x
export REPO="commaai"
S_BRANCH="$REPO/nlp-driving"
I_BRANCH="nlp-driving"
T_BRANCH="f150-dev"


export SOURCE_BRANCH=$S_BRANCH
export TARGET_BRANCH=$I_BRANCH
sh worker/_update_local.sh

export SOURCE_BRANCH=$I_BRANCH
export TARGET_BRANCH=$T_BRANCH
# sh worker/_update_branch.sh

git checkout ${SOURCE_BRANCH}
git branch -D ${TARGET_BRANCH}
git push origin --delete ${TARGET_BRANCH}

git branch ${TARGET_BRANCH}
git checkout ${TARGET_BRANCH}

# sed -e '/onnx/ s/^#*/#/' -i ../.gitattributes
# git add '../.gitattributes'
# cd ../selfdrive/modeld/models/
# git lfs untrack '*.onnx'
# git rm --cached '*.onnx'
# git add '*.onnx'
# #git add --renormalize .
# git commit -m "Restore file contents that were previously in LFS"
# git commit -m "restore '*.onnx' to git from lfs"

# F-150 14th Gen ONLY
git cherry-pick ba27e55360fe1b1a166577ff527455dda44ab014

# Ford: change LatCtlPrecision_D_Rq to comfortable
git cherry-pick df1e3af8d2e1f55a74163d1112f9941bdc2a77f4

# Lead ACC Data
git cherry-pick 5a6d48977bbbd1050f2bd25f839e4c37dae262ea

git push --no-verify --force --set-upstream origin ${TARGET_BRANCH} 

