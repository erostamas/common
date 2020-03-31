#/bin/bash

ROOT_DIR=$(git rev-parse --show-toplevel)

CMD='cd /workspace/common && mkdir -p build && rm -rf build/* && cd build && cmake ../ && make -j'

docker pull erostamas/common_build_raspbian_master
docker run -v $ROOT_DIR:/workspace/common erostamas/common_build_raspbian_master /bin/bash -c "${CMD}"
