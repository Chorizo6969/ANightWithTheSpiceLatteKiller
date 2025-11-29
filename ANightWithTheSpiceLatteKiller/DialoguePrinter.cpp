#include "DialoguePrinter.h"
#include <map>

#pragma region Constructor&Destructor
DialoguePrinter::DialoguePrinter(ConsolePrinter* consolePrinter) {
	dialogueDataBaseRef = new DialogueDataBase;
	consolePrinterRef_ = consolePrinter;
}

DialoguePrinter::~DialoguePrinter() {
	delete dialogueDataBaseRef;
}

#pragma endregion

void DialoguePrinter::WriteDialogue(std::string category, std::string key)
{
	std::cout << dialogueDataBaseRef->GetDialogue(category, key) << std::endl;
}


void DialoguePrinter::WriteDialogueWithDelay() 
{

}

void DialoguePrinter::WriteColoredDialogue(std::string category, std::string key, int colorIndex) {
	consolePrinterRef_->ColoredPrint(dialogueDataBaseRef->GetDialogue(category, key), colorIndex);
}

void DialoguePrinter::PrintInventory(int currentIngre, int maxIngre) {
	std::cout << "Ingredient Inventory : " << currentIngre << '/' << maxIngre << std::endl;
}
