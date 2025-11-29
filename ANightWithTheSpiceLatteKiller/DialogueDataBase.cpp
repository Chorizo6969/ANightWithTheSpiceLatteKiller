#include "DialogueDataBase.h"

DialogueDataBase::DialogueDataBase() {
    FillMap();
}

DialogueDataBase::~DialogueDataBase() {

}


void DialogueDataBase::FillMap() {
    // Utility
    UtilityDialogue["wait_dot"] = "... ... ...";
    UtilityDialogue["game_start"] = "Someone is hunting you. Find the ingredients and escape! Use [arrow keys] to move.";

    // Player
    PlayerDialogue["door_interact"] = "There's a door here. [A] Open it  |  [B] Listen carefully";
    PlayerDialogue["loot_interact"] = "You found an ingredient! Press [F] to take it.";

    // Killer
    KillerDialogue["try_open_door"] = "You hear someone frantically trying to open a door nearby. RUN!";
    KillerDialogue["game_over"] = "The killer found you. Everything fades to black...";
    KillerDialogue["in_next_room"] = "Heavy footsteps echo from the next room...";
    KillerDialogue["far_away"] = "Silence. For now.";
}


std::string DialogueDataBase::GetDialogue(const std::string& category, const std::string& key) const {
    if (category == "player") {
        auto it = PlayerDialogue.find(key);
        return (it != PlayerDialogue.end()) ? it->second : "ERROR: Dialogue not found";
    }
    else if (category == "killer") {
        auto it = KillerDialogue.find(key);
        return (it != KillerDialogue.end()) ? it->second : "ERROR: Dialogue not found";
    }
    else if (category == "utility") {
        auto it = UtilityDialogue.find(key);
        return (it != UtilityDialogue.end()) ? it->second : "ERROR: Dialogue not found";
    }
    return "ERROR: Unknown category";
}