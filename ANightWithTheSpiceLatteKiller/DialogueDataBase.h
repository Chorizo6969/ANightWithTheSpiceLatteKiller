#include <list>
#include <string>
#include <map>
#include <iostream>

#pragma once
class DialogueDataBase {
public:

	DialogueDataBase();

	~DialogueDataBase();

	std::string GetDialogue(const std::string& category, const std::string& key) const;

private:
	std::map<std::string, std::string> UtilityDialogue;
	std::map<std::string, std::string> KillerDialogue;
	std::map<std::string, std::string> PlayerDialogue;

	void FillMap();


};