#/bin/bash

cd $(dirname $0)/..

ROOT_DIR=$(git rev-parse --show-toplevel)
BRANCH_NAME=${BRANCH_NAME:-$(git rev-parse --abbrev-ref HEAD)}
IMAGE_NAME="erostamas/common_build_ubuntu_$BRANCH_NAME"

echo "Building in image: $IMAGE_NAME"

docker pull "$IMAGE_NAME"
docker run -v $ROOT_DIR:/workspace/common "$IMAGE_NAME" /bin/bash -c "/workspace/common/env/buildenv/ubuntu/build.sh && find /workspace/common/build/ -not -uid $(stat -c "%u" .) -exec chown --reference=. {} \;"
