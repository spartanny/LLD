#include "alley.h"
#include "lane.h"
#include<bits/stdc++.h>

using namespace std;

int main()
{
    Alley alley(5); // Alley of 5 lanes;
    // lets take lane 0 for instance
    Lane lane = alley.lanes[0];

    int num_of_players = 2;
    // Add num_of_players into this lane;
    // You can either take input of it or just define it here
    lane.addPlayers(num_of_players);
    cout << "Lane : " << lane.getId() << " , Number of Players : " << lane.getPlayers() << endl;
    
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