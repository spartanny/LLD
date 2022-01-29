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
        pair<int,int> result = {0,0}; // pair to store winner player and their score
        for (auto iter : score)
        {
            int id = iter.first;
            cout << id << " : " << iter.second << " " << players[id].getScore();
            cout << "\n";
            if(players[id].getScore() > result.second)
                result.first = id, result.second = players[id].getScore();
        }
        cout<<"Winner is Player-"<<result.first<<" with score "<<result.second<<"\n";
    }
};
