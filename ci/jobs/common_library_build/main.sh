#/bin/bash

echo "Building common library"

SUCCESS=0

cd $WORKSPACE/common
mkdir -p build
cd build
cmake ../.
make -j

SUCCESS=$?
echo "Done building common library "

return $SUCCESS