#include<vector>
#include "lane.h"

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
