#pragma once
#include <string>
#include <iostream>
#include "DialogueDatabase.h"
#include "ConsoleColorEnum.h"

class DialoguePrinter
{
public:
	DialogueDataBase* dialogueDataBaseRef;

	DialoguePrinter();
	~DialoguePrinter();

	void WriteDialogue(std::string category, std::string key);
	void WriteDialogueWithDelay();
	void WriteColoredDialogue(std::string category, std::string key, int colorIndex);
};

