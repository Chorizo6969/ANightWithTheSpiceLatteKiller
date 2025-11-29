#include "SoundManager.h"
#include <iostream>

SoundManager::SoundManager()
{
    if (ma_engine_init(NULL, &engine_) != MA_SUCCESS)
        std::cout << "Erreur init audio\n";

    PlayMusic("Ambiance.mp3", true);
}

SoundManager::~SoundManager()
{
    StopAllSFX();
    ma_engine_uninit(&engine_);
}

void SoundManager::PlayMusic(const std::string& fileName, bool isLoop)
{
    std::string fullPath = MusicPath + fileName;

    ma_sound* music = new ma_sound;
    if (ma_sound_init_from_file(&engine_, fullPath.c_str(), MA_SOUND_FLAG_STREAM, nullptr, nullptr, music) != MA_SUCCESS)
    {
        std::cout << "Erreur chargement musique : " << fullPath << "\n";
        delete music;
        return;
    }

    ma_sound_set_looping(music, isLoop);
    ma_sound_start(music);
}

void SoundManager::PlaySFX(const std::string& fileName)
{
    std::string fullPath = SFXPath + fileName;

    ma_sound* sfx = new ma_sound;

    if (ma_sound_init_from_file(&engine_, fullPath.c_str(),
        0, nullptr, nullptr, sfx) != MA_SUCCESS)
    {
        std::cout << "Erreur SFX : " << fullPath << "\n";
        delete sfx;
        return;
    }

    ma_sound_start(sfx);
    activeSFX_.push_back(sfx);
}

void SoundManager::StopLastSFX()
{
    if (activeSFX_.empty()) return;

    ma_sound* last = activeSFX_.back();
    ma_sound_stop(last);
    ma_sound_uninit(last);
    delete last;

    activeSFX_.pop_back();
}

void SoundManager::StopAllSFX()
{
    for (ma_sound* sfx : activeSFX_)
    {
        ma_sound_stop(sfx);
        ma_sound_uninit(sfx);
        delete sfx;
    }

    activeSFX_.clear();
}
