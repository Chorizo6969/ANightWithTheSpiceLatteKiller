#pragma once
#include "miniaudio.h"
#include <string>
#include <vector>

class SoundManager
{
public:
    std::string SFXPath = "Audio/SFX/";
    std::string MusicPath = "Audio/Musique/";

    void PlayMusic(const std::string& AudioPath, bool Isloop);
    void PlaySFX(const std::string& AudioPath);
    void StopLastSFX();
    void StopAllSFX();

    SoundManager();
    ~SoundManager();

private:
    ma_engine engine_;

    std::vector<ma_sound*> activeSFX_;
};
