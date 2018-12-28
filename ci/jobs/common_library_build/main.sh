#/bin/bash

echo "Building logging library"

SUCCESS=0

cd $WORKSPACE/logging
mkdir -p build
cd build
cmake ../.
make -j

SUCCESS=$?
echo "Done building logging library "

return $SUCCESS