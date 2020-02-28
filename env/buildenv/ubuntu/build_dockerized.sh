#/bin/bash

ROOT_DIR=$(git rev-parse --show-toplevel)
BRANCH_NAME=${GIT_BRANCH:-$(git rev-parse --abbrev-ref HEAD)}

CMD='cd /workspace/common && mkdir -p build && rm -rf build/* && cd build && cmake ../ && make -j'

IMAGE_NAME="erostamas/common_build_ubuntu_$BRANCH_NAME"

echo "Building in image: $IMAGE_NAME"

docker pull "$IMAGE_NAME"
docker run -v $ROOT_DIR:/workspace/common "$IMAGE_NAME" /bin/bash -c "${CMD}"
