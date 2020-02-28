#/bin/bash

set -e

echo "Building common deployment image for ubuntu as user $USER"

echo "Environment variables:"
env

export WORKSPACE="${WORKSPACE:-$(pwd)}"
SUCCESS=0

cd $WORKSPACE/common/
BRANCH_NAME=${BRANCH_NAME:-$(git rev-parse --abbrev-ref HEAD)}
ROOT_DIR=$(git rev-parse --show-toplevel)
echo "Branch name is: $BRANCH_NAME"

cd $WORKSPACE
docker build --build-arg branch=$BRANCH_NAME -t erostamas/common_deployment_ubuntu_$BRANCH_NAME -f $WORKSPACE/common/env/deploymentenv/ubuntu/Dockerfile $ROOT_DIR
docker login --username=erostamas --password 749af946-ad0c-4d57-ade7-dfcc06efb7e4 docker.io
docker push erostamas/common_deployment_ubuntu_$BRANCH_NAME:latest

SUCCESS=$?
echo "Done building common deployment image for ubuntu"

return $SUCCESS