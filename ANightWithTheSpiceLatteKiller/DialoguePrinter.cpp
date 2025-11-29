#include "DialoguePrinter.h"
#include <map>

//Constructor
DialoguePrinter::DialoguePrinter(ConsolePrinter* consolePrinter) {
	dialogueDataBaseRef = new DialogueDataBase;
	consolePrinterRef_ = consolePrinter;

}

//Destructor
DialoguePrinter::~DialoguePrinter() {
	delete dialogueDataBaseRef;
	delete consolePrinterRef_;
}


//Get the line from database and write in console
void DialoguePrinter::WriteDialogue(std::string category, std::string key)
{
	std::cout << dialogueDataBaseRef->GetDialogue(category, key) << std::endl;
}

//Futur function for gamefeel
void DialoguePrinter::WriteDialogueWithDelay() 
{

}

void DialoguePrinter::WriteColoredDialogue(std::string category, std::string key, int colorIndex) {
	consolePrinterRef_->ColoredPrint(dialogueDataBaseRef->GetDialogue(category, key), colorIndex);
}
