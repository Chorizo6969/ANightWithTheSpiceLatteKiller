#pragma once
#include <string>
#include <iostream>
#include "DialogueDatabase.h"


class DialoguePrinter
{
public:
	DialogueDataBase* dialogueDataBaseRef;

	DialoguePrinter();
	~DialoguePrinter();

	void WriteDialogue(std::string category, std::string key);
	void WriteDialogueWithDelay();
};

