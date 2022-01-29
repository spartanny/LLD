#include<bits/stdc++.h>
#include "player.h"
#include "scoreboard.h"
#pragma once
using namespace std;

class Lane
{
    int id;
    vector<Player> players;
    Scoreboard scoreboard;
    int rounds;
public:
    Lane(int id){
        this->id = id;
    }
    int getId(){
        return id;
    }
    void addPlayers(int n){
        for (int i = 0; i < n; i++)
            players.push_back(Player(i));
    }
    int getPlayers(){
        return players.size();
    }
    void setRounds(int rounds){
        this->rounds = rounds;
        for(int i=0;i<players.size();i++)
            players[i].setRounds(rounds);
    }
    int getRounds(){
        return rounds;
    }
    void showScore(){
        scoreboard.showScore(players);
    }
    void playChance(int pId,bool flag = false){
        if(flag){
            int temp;
            cin>>temp;
        }
        pair<int, int> score = players[pId].playChance();
        players[pId].setRounds(players[pId].getRounds()-1);
        string c1, c2;
        if (score.first == 10)
            c1 = "X", c2 = "";
        else if (score.first + score.second == 10)
            c1 = to_string(score.first), c2 = "/";
        else
            c1 = to_string(score.first), c2 = to_string(score.second);
        string chance = "{" + c1 + "," + c2 + "}";
        scoreboard.updateScore(pId, chance);
        // Allow player to play one more bonus chance if scored spare or strike on the last round
        if(players[pId].getRounds() == 0 and players[pId].getBonus() > 0){
            // rounds+=1;
            this->playChance(pId,true);
        }
    }
};