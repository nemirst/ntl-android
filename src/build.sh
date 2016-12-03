#!/bin/sh
export PATH=$PATH:/home/cppko/Android/Sdk/ndk-bundle/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin
make all && make check
