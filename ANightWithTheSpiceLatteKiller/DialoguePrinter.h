#pragma once
#include <string>
#include <iostream>
#include "DialogueDatabase.h"
#include "ConsolePrinter.h"
#include "ConsoleColorEnum.h"

class DialoguePrinter
{
public:
	DialogueDataBase* dialogueDataBaseRef;

	DialoguePrinter(ConsolePrinter* consolePrinter);
	~DialoguePrinter();

	//Get the line from database and write in console.category = player/killer/utility. key=exacte name of the dialogue
	void WriteDialogue(std::string category, std::string key);
	//Futur function for gamefeel
	void WriteDialogueWithDelay();

	void WriteColoredDialogue(std::string category, std::string key, int colorIndex);

	void PrintInventory(int currentIngre, int maxIngre);

private:
	ConsolePrinter* consolePrinterRef_;
};

