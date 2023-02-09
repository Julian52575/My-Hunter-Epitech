FROM ubuntu:18.04

#install necessary stuff
RUN apt-get update && \
    apt-get install -y \
        sudo \
        build-essential \
        gcc \
        make \
        libx11-dev freeglut3-dev libxcb-image0-dev libudev-dev libjpeg8-dev libopenal-dev libsndfile1-dev libfreetype6-dev libxrandr-dev \
        wget \
        unzip

#install csfml
RUN /bin/bash -c 'wget https://gist.github.com/paullaffitte/c3f028dc64a55e920fa8afabff70673e/archive/a3469c43b09b505be6a4279641e6ff5879b0def7.zip' && \
    unzip a3469c43b09b505be6a4279641e6ff5879b0def7.zip && \
    chmod +x c3f028dc64a55e920fa8afabff70673e-a3469c43b09b505be6a4279641e6ff5879b0def7/install-csfml.sh && \
    ./c3f028dc64a55e920fa8afabff70673e-a3469c43b09b505be6a4279641e6ff5879b0def7/install-csfml.sh

WORKDIR My-Hunter-Epitech
ENV PATH="/My-Hunter-Epitech:${PATH}"
