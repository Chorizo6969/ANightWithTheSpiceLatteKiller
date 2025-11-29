#include "DialoguePrinter.h"
#include <map>

//Constructor
DialoguePrinter::DialoguePrinter() {
	dialogueDataBaseRef = new DialogueDataBase;
}

//Destructor
DialoguePrinter::~DialoguePrinter() {
	delete dialogueDataBaseRef;
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
