#include <bits/stdc++.h>
using namespace std;

class Person
{
    int id;
    string name;
    int score;
    int rounds;
    int bonus;  // Used to represent either spare(1) or strike(2)
public:
    Person(int id)
    {
        this->id = id;
        this->name = "Person" + to_string(id);
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

class Scoreboard
{
    map<int, string> score;

public:
    void updateScore(int player, string chance)
    {
        score[player] = score[player] + chance + ", ";
    }
    void showScore(vector<Person> players)
    {
        for (auto iter : score)
        {
            int id = iter.first;
            cout << id << " : " << iter.second << " " << players[id].getScore();
            cout << "\n";
        }
    }
};

class Lane
{
    int id;
    vector<Person> players;
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
            players.push_back(Person(i));
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

class Alley
{
public:
    vector<Lane> lanes;
    Alley(int n)
    {
        for (int i = 0; i < n; i++)
        {
            lanes.push_back(Lane(i));
        }
    }
};

int main()
{
    Alley alley(5); // Alley of 5 lanes;
    // lets take lane 0 for instance
    Lane lane = alley.lanes[0];

    int num_of_players = 2;
    // Add num_of_players into this lane;
    lane.addPlayers(num_of_players);
    cout << "Lane : " << lane.getId() << " , Players : " << lane.getPlayers() << endl;
    
    // Input number of rounds and update that for the lane
    // printf("Specify number of rounds\n");
    int rounds;
    cin >> rounds;
    lane.setRounds(rounds);
    rounds *= num_of_players;
    // cout<<rounds<<endl;

    while (true)
    {
        if (rounds == 0)
            break;
        int pId;
        cin >> pId;
        lane.playChance(pId - 1);
        --rounds;
        // cout<<rounds<<endl;
    }
    lane.showScore();
}

/*
1 Alley , Many Players
classes : Alley(Infor about number of Lanes){
            vector<BowlingLanes>
          },
          Players(The user at the bowling lane){
              id,
              score
          },
          BowlingLane (Individual Lane where players interact){
              vector<Players>
              scoreboard
          }
Input
3 ( Rounds)
following lines have p,c1,c2 : p is the player identifier, c1 and c2 its respective scores in 2 throws
1 8 2
2 10
1 3 6
2 6 4
1 10
2 8 2
*/