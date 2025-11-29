#include "LatteComposant.h"
#include "MapManager.h"
#include <iostream>
#include <random>

void LatteComposant::CreateLatteComposant(MapManager* mapManager)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    for (auto& entry : mapManager->CharPosMapByRoom)
    {
        const char roomChar = entry.first;

        if (std::find(forbiddenCharacters_.begin(), forbiddenCharacters_.end(), roomChar) != forbiddenCharacters_.end())
            continue; // caractère interdit

        auto& positions = entry.second;

        if (positions.empty())
            continue;

        std::uniform_int_distribution<size_t> dist(0, positions.size() - 1);
        size_t index = dist(gen);

        std::pair <float,float> pos = positions[index];
        int x = pos.first;
        int y = pos.second;

        //mapManager->Map[y][x] = '@';
        mapManager->LatteComponentsPos.push_back(make_pair(x, y));
    }

    std::cout << "[LatteComposant] Collectibles générés !\n";
}
