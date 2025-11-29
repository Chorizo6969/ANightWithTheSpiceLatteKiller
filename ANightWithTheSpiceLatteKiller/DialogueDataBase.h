#pragma once

#include <list>
#include <string>
#include <map>
#include <iostream>


class DialogueDataBase {
public:

	DialogueDataBase();

	~DialogueDataBase();

	//Safe way to get line. category = player/killer/utility. key=exacte name of the dialogue
	std::string GetDialogue(const std::string& category, const std::string& key) const;


private:
	std::map<std::string, std::string> UtilityDialogue;
	std::map<std::string, std::string> KillerDialogue;
	std::map<std::string, std::string> PlayerDialogue;

	//Fill the map on construct
	void FillMap();
};