#include <string>
#include <iostream>
#include "DialogueDatabase.h"

#pragma once
class DialogueUI
{
public:
	DialogueDataBase* dialogueDataBaseRef;

	DialogueUI();
	~DialogueUI();

	void WriteDialogue(std::string category, std::string key);
	void WriteDialogueWithDelay();
};

