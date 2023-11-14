#!/bin/bash

set +x

echo $SOURCE_BRANCH
echo $TARGET_BRANCH

git checkout ${SOURCE_BRANCH}
git branch -D ${TARGET_BRANCH}
# git push origin --delete ${TARGET_BRANCH}

git branch ${TARGET_BRANCH}
git checkout ${TARGET_BRANCH}

if [ "$REPO" = "sunny" ]; then
    # Add Disclaimer
    git cherry-pick 26d1550a5adc83e27c66d4b4ed9cf4657a34ea57
fi

# F-150 14th Gen ONLY
git cherry-pick bd4d03b0e594e463ed12e336f347a7f896b03368

# Ford: change LatCtlPrecision_D_Rq to comfortable
git cherry-pick 43d34b1f4bb7d233e20b6bdbf085c3f4483dc015

# Lead ACC Data
git cherry-pick 19f2f6ef17d1df534a30b3629906aa67141c68c1

# Add byte size offset for some CAN-FD vehicles
git cherry-pick 3c71d614c9fa459ff48aa8123473c5434798d31f

# Fingerprinting
# Truck A
git cherry-pick f46e78378662af9749b52950dd502e89c3172026

# Truck B
git cherry-pick d48a583d1755b1d4c55cc78e8968d653e7ede5bf

# remove hardcoded figerprint
git cherry-pick 35050188c79137073af708b93a3cf9a9baa60fb0

if [ "$REPO" = "sunny" ]; then
    # Increase the LCA takeover time to 5 seconds after blinker
    git cherry-pick cf90d1bbf0fb4ebbe02e424b78081df2a8ec5086
    git cherry-pick 647a371a2e0e02bc22ce87a804c5f8b7755b7d61
fi

git push --force --set-upstream origin ${TARGET_BRANCH} 
