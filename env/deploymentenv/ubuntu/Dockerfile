ARG branch
FROM erostamas/common_build_ubuntu_$branch:latest
MAINTAINER Tamas Eros (tamas.eros1@gmail.com)

COPY ./ /repos/common/
WORKDIR /repos/common/
RUN env/buildenv/ubuntu/build.sh
WORKDIR /repos/common/build/
RUN make install