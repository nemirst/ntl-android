#!/bin/sh

export NDK_DIR=$HOME/Android/Sdk/ndk-bundle
ORIG_PATH=$PATH

mkdir -p ../build

# Rest of ABI builds commented out because there must be one device
# connected at the time of build.
# ANDROID_ABI=armeabi
# mkdir -p ../build/$ANDROID_ABI
# export PATH=$ORIG_PATH:$NDK_DIR/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin
# make all TARGET_ARCH_ABI=$ANDROID_ABI
# if [ $? -eq 0 ]; then
#     cp -r ../include/NTL ../build/$ANDROID_ABI
#     cp ntl.a ../build/$ANDROID_ABI/libntl.a
# fi

# ANDROID_ABI=armeabi-v7a
# mkdir -p ../build/$ANDROID_ABI
# export PATH=$ORIG_PATH:$NDK_DIR/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin
# make all TARGET_ARCH_ABI=$ANDROID_ABI
# if [ $? -eq 0 ]; then
#     cp -r ../include/NTL ../build/$ANDROID_ABI
#     cp ntl.a ../build/$ANDROID_ABI/libntl.a
# fi

ANDROID_ABI=arm64-v8a
mkdir -p ../build/$ANDROID_ABI
export PATH=$ORIG_PATH:$NDK_DIR/toolchains/aarch64-linux-android-4.9/prebuilt/linux-x86_64/bin
make all TARGET_ARCH_ABI=$ANDROID_ABI
if [ $? -eq 0 ]; then
    cp -r ../include/NTL ../build/$ANDROID_ABI
    cp ntl.a ../build/$ANDROID_ABI/libntl.a
fi

# cppkonsultants: compilation doesn't work for make check currently,
# commented out
# && make check
