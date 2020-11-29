// https://leetcode.com/problems/jump-game/

#include <algorithm>
#include <iostream>
#include <list>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool canJump(vector<int> &nums)
{
    int reach = 0;

    for (int i = 0; i < nums.size() && reach < nums.size(); i++)
    {
        if (i <= reach)
        {
            reach = max(reach, i + nums[i]);
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{

    vector<int> a{2, 0};
    // vector<int> a{2, 3, 1, 1, 4};

    cout << canJump(a);

    getchar();

    return 0;
}