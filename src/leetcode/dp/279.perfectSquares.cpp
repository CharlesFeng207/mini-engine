// https://leetcode.com/problems/perfect-squares/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int numSquares(int n)
{
    if (n <= 0)
        return 0;

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int minLen = INT_MAX;

        for (int j = 1; j * j <= i; j++)
        {
            minLen = min(minLen, 1 + dp[i - j * j]);
        }

        dp[i] = minLen;
    }

    return dp[n];
}

int numSquares_static_dp(int n)
{
    if (n <= 0)
        return 0;

    static vector<int> dp{0};

    while (dp.size() < n + 1)
    {
        int i = dp.size();

        int minLen = INT_MAX;

        for (int j = 1; j * j <= i; j++)
        {
            minLen = min(minLen, 1 + dp[i - j * j]);
        }

        dp.push_back(minLen);
    }

    return dp[n];
}

int main()
{
    cout << numSquares(12) << endl;
    cout << numSquares(13) << endl;
    cout << numSquares(32349) << endl;

    cout << "----------- " << endl;

    cout << numSquares_static_dp(12) << endl;
    cout << numSquares_static_dp(13) << endl;
    cout << numSquares_static_dp(32349) << endl;

    getchar();
    return 0;
}