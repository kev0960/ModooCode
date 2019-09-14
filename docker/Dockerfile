FROM ubuntu:disco
MAINTAINER jblee94

RUN apt-get update

RUN apt-get install -y git
RUN apt-get install -y clang
RUN apt-get install -y cmake
RUN apt-get install -y libssl-dev
RUN apt-get install -y libpqxx-dev
RUN apt-get install -y clang-format
RUN apt-get install -y wget
RUN apt-get install -y libzmq3-dev

RUN git clone https://github.com/kev0960/modoocode --depth=5
RUN git clone https://github.com/nvm-sh/nvm.git .nvm

SHELL ["/bin/bash", "--login", "-c"]
WORKDIR "/.nvm"
RUN ./install.sh
