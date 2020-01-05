#/bin/bash

echo "Building common library"

cd $WORKSPACE/common/
$WORKSPACE/common/env/buildenv/ubuntu/build.sh

echo "Done building common library "
