// https://leetcode.com/problems/target-sum/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void update(unordered_map<int, int> &map, int sum, int count)
{
    if (map.find(sum) == map.end())
        map[sum] = 0;

    map[sum] += count;
}

int findTargetSumWays(vector<int> &nums, int S)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    vector<unordered_map<int, int>> dp(n, unordered_map<int, int>());

    if (nums[0] == 0)
    {
        dp[0][0] = 2;
    }
    else
    {
        dp[0][nums[0]] = 1;
        dp[0][-nums[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        auto iter = dp[i - 1].begin();
        while (iter != dp[i - 1].end())
        {
            update(dp[i], iter->first + nums[i], iter->second);
            update(dp[i], iter->first - nums[i], iter->second);
            iter++;
        }
    }

    if (dp[n - 1].find(S) == dp[n - 1].end())
        return 0;

    return dp[n - 1][S];
}

int main()
{
    vector<int> a{1, 1, 1, 1, 1};
    cout << findTargetSumWays(a, 3) << endl;

    vector<int> a1{0, 0, 0, 0, 0, 0, 0, 0, 1};
    cout << findTargetSumWays(a1, 1) << endl;

    getchar();
    return 0;
}
