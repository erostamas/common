#/bin/bash

OPERATING_SYSTEM="$1"

set -e

echo "Building common build image for $OPERATING_SYSTEM as user: $USER"

echo "Environment variables:"
env

export WORKSPACE="${WORKSPACE:-$(pwd)}"
SUCCESS=0

cd $WORKSPACE/common/
BRANCH_NAME=${BRANCH_NAME:-$(git rev-parse --abbrev-ref HEAD)}
IMAGE_NAME="erostamas/common_build_${OPERATING_SYSTEM}_${BRANCH_NAME}"
echo "Image name is: $IMAGE_NAME, branch name is: $BRANCH_NAME"

cd $WORKSPACE
docker build -t "$IMAGE_NAME" $WORKSPACE/common/env/buildenv/$OPERATING_SYSTEM/
docker login --username=erostamas --password 749af946-ad0c-4d57-ade7-dfcc06efb7e4 docker.io
docker push "$IMAGE_NAME":latest

SUCCESS=$?
echo "Done building common build image for $OPERATING_SYSTEM"

return $SUCCESS