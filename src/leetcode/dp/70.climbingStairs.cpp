// https://leetcode.com/problems/climbing-stairs

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int climbStairs(int n)
{
    if (n <= 0)
        return 0;

    vector<int> dp(max(n, 2), 0);

    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i < n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n - 1];
}

int main()
{
    cout << climbStairs(10) << endl;
    cout << climbStairs(1) << endl;
    getchar();
    return 0;
}