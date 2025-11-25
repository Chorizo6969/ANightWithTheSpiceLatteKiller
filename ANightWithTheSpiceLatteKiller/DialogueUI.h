#include <string>
#include <iostream>
#include "DialogueDatabase.h"

#pragma once
class DialogueUI
{
public:
	DialogueDataBase* dialogueDataBaseRef;

	void WriteDialogue(std::string category, std::string key);
	void WriteDialogueWithDelay();
	void WriteAllDialogueFromMap(const std::map<std::string, std::string>& mapName)
};

