#!/bin/sh
export PATH=$PATH:/home/cppko/Android/Sdk/ndk-bundle/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin
make all
# cppkonsultants: compilation doesn't work for make check currently,
# commented out
# && make check
