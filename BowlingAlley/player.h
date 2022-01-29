#include <iostream>
using namespace std;
#pragma once
class Player
{
    int id;
    string name;
    int score;
    int rounds;
    int bonus;  // Used to represent either spare(1) or strike(2)
public:
    Player(int id)
    {
        this->id = id;
        this->name = "Player" + to_string(id);
        this->score = 0;
        this->rounds = 0;
        this->bonus = 0;
    }
    string getName()
    {
        return name;
    }
    int getScore()
    {
        return score;
    }
    void setRounds(int rounds){
        this->rounds = rounds;
    }
    int getRounds(){
        return rounds;
    }
    int getBonus(){
        return bonus;
    }
    pair<int, int> playChance()
    {   
        int c1, c2;
        cin >> c1;
        if (c1 < 10){
            cin >> c2;
        }else{
            c2 = 0;
        }
        cout << "Player"<< id << " " << c1 << ":" << c2 << ":" << bonus<< endl;
        if(bonus == 1)  score += c1*2 + c2;
        else if(bonus == 2)  score += (c1+c2)*2;
        else score += c1+c2;

        if(c1 == 10)    bonus = 2;
        else if(c1 + c2 == 10)   bonus = 1;
        else bonus = 0;
        
        return {c1, c2};
    };
};