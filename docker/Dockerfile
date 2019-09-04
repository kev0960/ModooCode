FROM ubuntu:disco
MAINTAINER jblee94

RUN apt update

RUN apt install -y git
RUN apt install -y clang
RUN apt install -y cmake
RUN apt install -y libssl-dev
RUN apt install -y libpqxx-dev
RUN apt install -y clang-format
RUN apt install -y wget
RUN apt install -y libzmq3-dev

RUN git clone https://github.com/kev0960/modoocode --depth=5
RUN git clone https://github.com/nvm-sh/nvm.git .nvm
WORKDIR "/.nvm"
RUN ./install.sh
WORKDIR "/root"
RUN source .bashrc
WORKDIR "/"
RUN nvm install --lts


