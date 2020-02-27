#/bin/bash

ROOT_DIR=$(git rev-parse --show-toplevel)
BRANCH=$(git rev-parse --abbrev-ref HEAD)

CMD='cd /workspace/common && mkdir -p build && rm -rf build/* && cd build && cmake ../ && make -j'

echo "Branch is: $BRANCH"
docker pull erostamas/common_build_ubuntu_$BRANCH
docker run -v $ROOT_DIR:/workspace/common erostamas/common_build_ubuntu_$BRANCH /bin/bash -c "${CMD}"
