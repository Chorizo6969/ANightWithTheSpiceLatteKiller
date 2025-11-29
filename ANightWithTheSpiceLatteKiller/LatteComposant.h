#pragma once
#include <vector>

class MapManager;

class LatteComposant {
public:

    void CreateLatteComposant(MapManager* map);

private:
    std::vector<char> forbiddenCharacters_ = {
        '#', ' ', //mur et vide
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '[', ')', '/', '$', '}', '<', ']', '(', '>', '{' //DoorSymbols de MapManager
    };
};
