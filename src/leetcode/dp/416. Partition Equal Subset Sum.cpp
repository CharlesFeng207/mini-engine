// https://leetcode.com/problems/partition-equal-subset-sum

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// https://leetcode.com/problems/partition-equal-subset-sum/discuss/90592/01-knapsack-detailed-explanationc
// This problem is essentially let us to find whether there are several numbers in a set which are able to sum to a specific value
// (in this problem, the value is sum/2).
bool canPartition(vector<int> &nums)
{
    if (nums.size() == 0)
        return false;

    int sum = accumulate(nums.begin(), nums.end(), 0);

    if ((sum & 1) == 1)
        return false;

    sum /= 2;

    vector<vector<bool>> dp(nums.size() + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i <= nums.size(); i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
            {
                dp[i][j] = true;
            }
            else if (i == 0)
            {
                dp[i][j] = false;
            }
            else if (j < nums[i - 1])
            {
                dp[i][j] = false;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    return dp[nums.size()][sum];
}

int main()
{
    vector<int> a{1, 5, 11, 5};
    cout << canPartition(a) << endl;
    getchar();
    return 0;
}