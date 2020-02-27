#/bin/bash

set -e

echo "Building common build image for ubuntu"

echo "Environment variables:"
env

export WORKSPACE="${WORKSPACE:-$(pwd)}"
SUCCESS=0

cd $WORKSPACE/common/
BRANCH_NAME=$(git rev-parse --abbrev-ref HEAD)
echo "Branch name is: $BRANCH_NAME"

cd $WORKSPACE
docker build -t erostamas/common_build_ubuntu_$BRANCH_NAME $WORKSPACE/common/env/buildenv/ubuntu/
docker login --username=erostamas --password 749af946-ad0c-4d57-ade7-dfcc06efb7e4 docker.io
docker push erostamas/common_build_ubuntu_$BRANCH_NAME:latest

SUCCESS=$?
echo "Done building common build image for ubuntu"

return $SUCCESS