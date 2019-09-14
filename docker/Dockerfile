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

# Use /bin/bash as a default shell
SHELL ["/bin/bash", "-c"]

ENV NVM_DIR /usr/local/nvm
RUN mkdir $NVM_DIR

ENV NODE_VERSION 10.16.3
RUN wget -qO- https://raw.githubusercontent.com/nvm-sh/nvm/v0.34.0/install.sh | bash

# install node and npm LTS
RUN source $NVM_DIR/nvm.sh \
    && nvm install $NODE_VERSION \
    && nvm alias default $NODE_VERSION \
    && nvm use default 

# add node and npm to path so the commands are available
ENV NODE_PATH $NVM_DIR/v$NODE_VERSION/lib/node_modules
ENV PATH $NVM_DIR/versions/node/v$NODE_VERSION/bin:$PATH

# confirm installation of node
RUN node -v
RUN npm -v

WORKDIR /modoocode
RUN npm install

ENV HASH_ROUNDS 8
ENV SESSION_SECRET do_num_run_on_prod_server 
ENV SERVER_ENV DEBUG 
ENV IN_WINDOWS_FOR_DEBUG true
