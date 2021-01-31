FROM balenalib/raspberrypi3:latest
MAINTAINER Tamas Eros (tamas.eros1@gmail.com)

RUN apt-get update --fix-missing
RUN DEBIAN_FRONTEND="noninteractive" apt-get -y install tzdata
RUN apt-get install -y build-essential \
                       git \
                       cmake \
                       libgmock-dev \
                       libboost-log-dev \
                       libboost-system-dev \
                       libboost-thread-dev