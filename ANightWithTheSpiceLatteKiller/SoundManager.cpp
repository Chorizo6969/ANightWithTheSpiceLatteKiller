#include "SoundManager.h"
#include <iostream>

SoundManager::SoundManager()
{
    if (ma_engine_init(NULL, &engine) != MA_SUCCESS)
    {
        std::cout << "Erreur init audio\n";
    }
}

SoundManager::~SoundManager()
{
    ma_engine_uninit(&engine);
}

void SoundManager::PlayMusic(const std::string& fileName, bool isLoop)
{
    std::string fullPath = MusicPath + fileName;

    ma_sound* music = new ma_sound;
    if (ma_sound_init_from_file(&engine, fullPath.c_str(),
        MA_SOUND_FLAG_STREAM, nullptr, nullptr, music) != MA_SUCCESS)
    {
        std::cout << "Erreur chargement musique : " << fullPath << "\n";
        delete music;
        return;
    }

    std::cout << fullPath << "\n";
    ma_sound_set_looping(music, isLoop);
    ma_sound_start(music);
}

void SoundManager::PlaySFX(const std::string& fileName)
{
    std::string fullPath = SFXPath + fileName;

    if (ma_engine_play_sound(&engine, fullPath.c_str(), nullptr) != MA_SUCCESS)
    {
        std::cout << "Erreur chargement SFX : " << fullPath << "\n";
    }
}
