#!/bin/bash
clear
cd ..
mkdir out
echo "Building Raspberry Pi x64 sample"
g++ -Wno-psabi \
src/common/mainAudio.cpp \
src/linux/LinuxAudioPlayer.cpp \
src/common/AudioPlayerEntry.cpp \
src/common/AgentConfiguration.cpp \
src/common/DeviceStatusIndicators.cpp \
-o ./out/sample.exe \
-std=c++14 \
-D LINUX \
-L./lib/x64 \
-I./include/cxx_api \
-I./include/c_api \
-I./include \
-pthread \
-lasound \
-lMicrosoft.CognitiveServices.Speech.core

cp ./scripts/run.sh ./out
chmod +x ./out/run.sh
