#include "miniaudio.h"
#include <string>

#pragma once
class SoundManager
{
public:
	std::string SFXPath = "Audio/SFX/";
	std::string MusicPath = "Audio/Musique/";

	const char* path = nullptr;

	void PlayMusic(const std::string& AudioPath, bool Isloop);
	void PlaySFX(const std::string& AudioPath);

	SoundManager();
	~SoundManager();

private:
	ma_engine engine;
};

