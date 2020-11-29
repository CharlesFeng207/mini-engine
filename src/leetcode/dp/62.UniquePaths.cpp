// https://leetcode.com/problems/unique-paths/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int uniquePaths(int m, int n)
{
    if (m <= 0 || n <= 0)
        return 0;

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[n - 1][m - 1];
}

int main()
{
    cout << uniquePaths(3, 2) << endl;
    cout << uniquePaths(7, 3) << endl;
    getchar();
    return 0;
}