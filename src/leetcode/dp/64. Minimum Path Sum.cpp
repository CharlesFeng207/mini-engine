// https://leetcode.com/problems/minimum-path-sum/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    if (grid.size() == 0 || grid[0].size() == 0)
    {
        return 0;
    }

    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[0][0] = grid[0][0];
                continue;
            }

            auto up = i == 0 ? INT_MAX : dp[i - 1][j];
            auto left = j == 0 ? INT_MAX : dp[i][j - 1];

            dp[i][j] = min(up, left) + grid[i][j];
        }
    }

    return dp[rows - 1][cols - 1];
}

int main()
{
    // Create numeric triangle
    int row = 30;

    vector<vector<int>> a;
    for (int i = 0; i < row; i++)
    {
        auto v = &a.emplace_back();
        for (int j = 0; j < row; j++)
        {
            v->push_back(j <= i ? rand() % 10 : 0);
        }
    }

    // Display
    for (auto &i : a)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << "minPathSum:" << minPathSum(a) << endl;

    getchar();
}