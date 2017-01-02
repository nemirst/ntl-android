#!/bin/sh

export NDK_DIR=$HOME/Android/Sdk/ndk-bundle
ORIG_PATH=$PATH

# Only one build type uncommented because there must be one device
# connected at the time of build.

## --- armeabi ---
# export ANDROID_ABI=armeabi
# mkdir -p ../prebuilt/$ANDROID_ABI
# export PATH=$ORIG_PATH:$NDK_DIR/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin
# make all
# if [ $? -eq 0 ]; then
#     cp -r ../include/NTL ../prebuilt/$ANDROID_ABI
#     arm-linux-androideabi-strip --strip-unneeded ntl.a
#     cp ntl.a ../prebuilt/$ANDROID_ABI/libntl.a
# fi
# make check
# make clobber

## --- armeabi-v7a ---
# export ANDROID_ABI=armeabi-v7a
# mkdir -p ../prebuilt/$ANDROID_ABI
# export PATH=$ORIG_PATH:$NDK_DIR/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin
# make all
# if [ $? -eq 0 ]; then
#     cp -r ../include/NTL ../prebuilt/$ANDROID_ABI
#     arm-linux-androideabi-strip --strip-unneeded ntl.a
#     cp ntl.a ../prebuilt/$ANDROID_ABI/libntl.a
# fi
# make check
# make clobber

## --- arm64-v8a ---
export ANDROID_ABI=arm64-v8a
mkdir -p ../prebuilt/$ANDROID_ABI
export PATH=$ORIG_PATH:$NDK_DIR/toolchains/aarch64-linux-android-4.9/prebuilt/linux-x86_64/bin
make all
if [ $? -eq 0 ]; then
    cp -r ../include/NTL ../prebuilt/$ANDROID_ABI
    aarch64-linux-android-strip --strip-unneeded ntl.a
    cp ntl.a ../prebuilt/$ANDROID_ABI/libntl.a
fi
make check
make clobber
