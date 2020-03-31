FROM balenalib/raspberrypi3:latest

MAINTAINER Tamas Eros (tamas.eros1@gmail.com)

RUN apt-get update && apt-get install -y build-essential \
                       git \
                       cmake \
                       libboost-log-dev \
                       libboost-system-dev \
                       libboost-thread-dev \
                       google-mock

# Build and install gmock libraries from source
RUN mkdir /usr/src/googletest/build
WORKDIR /usr/src/googletest/build
RUN cmake ../
RUN make -j
RUN cp googlemock/libgmock.a /usr/lib/
RUN cp googlemock/libgmock_main.a /usr/lib/