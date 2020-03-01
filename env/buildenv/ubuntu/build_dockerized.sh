#/bin/bash

cd $(dirname $0)/..

ROOT_DIR=$(git rev-parse --show-toplevel)
BRANCH_NAME=${BRANCH_NAME:-$(git rev-parse --abbrev-ref HEAD)}
IMAGE_NAME="erostamas/common_build_ubuntu_$BRANCH_NAME"

echo "Building in image: $IMAGE_NAME"


CMD="/workspace/common/env/buildenv/ubuntu/build.sh && chown -R $UID:$UID /workspace/common/build/*"
docker pull "$IMAGE_NAME"
docker run -v $ROOT_DIR:/workspace/common "$IMAGE_NAME" /bin/bash -c "$CMD"
