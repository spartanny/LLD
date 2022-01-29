#include<iostream>
#include<map>
#include<vector>
#include "player.h"
#pragma once
using namespace std;

class Scoreboard
{
    map<int, string> score;

public:
    void updateScore(int player, string chance)
    {
        score[player] = score[player] + chance + ", ";
    }
    void showScore(vector<Player> players)
    {
        for (auto iter : score)
        {
            int id = iter.first;
            cout << id << " : " << iter.second << " " << players[id].getScore();
            cout << "\n";
        }
    }
};
