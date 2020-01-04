FROM ubuntu:latest
MAINTAINER Tamas Eros (tamas.eros1@gmail.com)

RUN apt-get update
RUN apt-get install -y build-essential \
                       git \
                       cmake \
                       libboost-all-dev \
                       google-mock

# Build and install gmock libraries from source
RUN mkdir /usr/src/googletest/build
WORKDIR /usr/src/googletest/build
RUN cmake ../
RUN make -j
RUN cp googlemock/libgmock.a /usr/lib/
RUN cp googlemock/libgmock_main.a /usr/lib/