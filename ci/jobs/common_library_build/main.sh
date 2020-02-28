#/bin/bash

echo "Building common library as user: $USER"

echo "Environment variables:"
env

cd $WORKSPACE/common/
$WORKSPACE/common/env/buildenv/ubuntu/build_dockerized.sh

echo "Done building common library "
