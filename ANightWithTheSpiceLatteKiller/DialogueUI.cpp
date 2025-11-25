#include "DialogueUI.h"
#include <map>

//Constructor
DialogueUI::DialogueUI() {
	dialogueDataBaseRef = new DialogueDataBase;
}

//Destructor
DialogueUI::~DialogueUI() {
	delete dialogueDataBaseRef;
}


//Get the line from database and write in console
void DialogueUI::WriteDialogue(std::string category, std::string key)
{
	std::cout << dialogueDataBaseRef->GetDialogue(category, key) << std::endl;
}

//Futur function for gamefeel
void DialogueUI::WriteDialogueWithDelay() 
{

}
