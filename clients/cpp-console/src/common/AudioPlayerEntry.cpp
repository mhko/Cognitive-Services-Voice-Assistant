// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#include <cstring>
#include <memory>
#include "AudioPlayerEntry.h"

using namespace AudioPlayer;
using namespace Microsoft::CognitiveServices::Speech;

AudioPlayerEntry::AudioPlayerEntry(unsigned char* pData, size_t pSize){
    m_entryType = PlayerEntryType::BYTE_ARRAY;
    m_size = pSize;
    m_data = (unsigned char *)malloc(pSize);
    if (m_data) {
        memcpy(m_data, pData, pSize);
    }
};

AudioPlayerEntry::AudioPlayerEntry(std::shared_ptr<Audio::PullAudioOutputStream> pStream){
    m_entryType = PlayerEntryType::PULL_AUDIO_OUTPUT_STREM;
    m_pullStream = pStream;
};
