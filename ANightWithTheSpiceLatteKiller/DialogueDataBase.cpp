#include "DialogueDataBase.h"

DialogueDataBase::DialogueDataBase() {
    FillMap();
}

DialogueDataBase::~DialogueDataBase() {

}

void DialogueDataBase::FillMap() {
    // Utility
    UtilityDialogue["wait_dot"] = ".... .... ....";

    // Player
    PlayerDialogue["door_interact"] = "A door is just here, what do you want to do?";
    PlayerDialogue["choice_open"] = "A - Open the door";
    PlayerDialogue["choice_listen"] = "B - Listen to the sound";
    PlayerDialogue["open_door"] = "You choose to open the door";
    PlayerDialogue["listen_sound"] = "You choose to listen";
    PlayerDialogue["loot_item"] = "You loot this : ";

    // Killer
    KillerDialogue["try_open_door"] = "You can hear the killer trying to open one of the doors!";
    KillerDialogue["kill_you"] = "The killer found you, you are dead.....";
    KillerDialogue["in_next_room"] = "You hear breath just in the next room";
    KillerDialogue["far_away"] = "You hear nothing";
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

void DialogueDataBase::DebugDialogueData() {
    std::cout << GetDialogue("player", "door_interact") << std::endl;
}