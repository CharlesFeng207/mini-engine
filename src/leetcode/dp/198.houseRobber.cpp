// https://leetcode.com/problems/house-robber/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// O(n)
int rob(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    vector<int> dp(nums.size());
    dp[0] = nums[0];

    int maxMoney = dp[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int m = 0;
        for (int j = 0; j < i - 1; j++)
        {
            m = max(m, dp[j]);
        }

        dp[i] = m + nums[i];
        maxMoney = max(maxMoney, dp[i]);
    }

    return maxMoney;
}

int main()
{
    vector<int> a{2, 7, 9, 3, 1};
    vector<int> b{1};
    vector<int> c{2, 5, 17, 3, 9, 28, 19, 29, 5, 7, 31};

    cout << rob(a) << endl;
    cout << rob(b) << endl;
    cout << rob(c) << endl;
    getchar();
    return 0;
}