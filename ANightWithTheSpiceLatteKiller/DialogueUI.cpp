#include "DialogueUI.h"
#include <map>

void DialogueUI::WriteDialogue(std::string category, std::string key)
{
	std::cout << dialogueDataBaseRef->GetDialogue(category, key) << std::end;
}

void DialogueUI::WriteDialogueWithDelay() 
{

};

void DialogueUI::WriteAllDialogueFromMap(const std::map<std::string, std::string>& mapName) {
    for (const auto& [key, value] : mapName) {
        std::cout << "Clé: " << key << " | Valeur: " << value << std::endl;
    }
}
