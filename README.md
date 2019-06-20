COMMON

#INSTALL BOOST

'''
sudo apt-get install libboost-all-dev
'''

#INSTALL CPP-REDIS

'''
git clone https://github.com/Cylix/cpp_redis.git
cd cpp_redis
git submodule init && git submodule update
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make
sudo make install
'''

#INSTALL GMOCK
'''
sudo apt-get install google-mock
cd /usr/src/gtest
mkdir build && cd build
sudo cmake ../
sudo make -j
ls build/libgtest*
build/libgtest.a  build/libgtest_main.a
sudo cp libgmock* /usr/lib/
'''
