#include <bits/stdc++.h>
using namespace std;

class Person
{
    int id;
    string name;
    int score;

public:
    Person(int id)
    {
        this->id = id;
        this->name = "Person" + to_string(id);
        this->score = 0;
    }
    string getName()
    {
        return name;
    }
    int getScore()
    {
        return score;
    }
    pair<int, int> playChance()
    {
        int c1, c2;
        cin >> c1;
        if (c1 < 10)
        {
            cin >> c2;
        }
        else
        {
            c2 = 0;
        }
        cout << id << " " << c1 << ":" << c2 << endl;
        score += c1 + c2;
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

public:
    int rounds;
    Lane(int id)
    {
        this->id = id;
    }
    void setRounds(int rounds)
    {
        this->rounds = rounds;
    }
    int getId()
    {
        return id;
    }
    void addPlayers(int n)
    {
        for (int i = 0; i < n; i++)
            players.push_back(Person(i));
    }
    int getPlayers()
    {
        return players.size();
    }
    void showScore()
    {
        scoreboard.showScore(players);
    }
    void playChance(int pId)
    {
        pair<int, int> score = players[pId].playChance();
        string c1, c2;
        if (score.first == 10)
            c1 = "X", c2 = "";
        else if (score.first + score.second == 10)
            c1 = to_string(score.first), c2 = "/";
        else
            c1 = to_string(score.first), c2 = to_string(score.second);
        string chance = "{" + c1 + "," + c2 + "}";
        scoreboard.updateScore(pId, chance);
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
    Lane l = alley.lanes[0];

    int num_of_players = 2;
    // Add num_of_players into this lane;
    l.addPlayers(num_of_players);
    cout << "Lane : " << l.getId() << " , Players : " << l.getPlayers() << endl;

    // Input number of rounds and update that for the lane
    printf("Specify number of rounds\n");
    int rounds;
    cin >> rounds;
    l.setRounds(rounds);
    // cout<<rounds<<endl;
    rounds *= num_of_players;

    while (true)
    {
        if (rounds == 0)
            break;
        int pId;
        cin >> pId;
        l.playChance(pId - 1);
        rounds--;
        // cout<<rounds<<endl;
    }
    l.showScore();

    cout << endl;
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