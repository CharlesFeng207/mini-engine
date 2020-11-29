#include <algorithm>
#include <iostream>
#include <time.h>
#include <unordered_map>
#include <vector>

using namespace std;

int maximalSquare(vector<vector<char>> &matrix)
{
    int row = matrix.size();
    if (row == 0)
        return 0;

    int col = matrix[0].size();
    if (col == 0)
        return 0;

    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
    int result = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            dp[i][j] = matrix[i][j] - '0'; // char to int.
            if (i != 0 && j != 0 && dp[i][j] == 1)
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }

            result = max(result, dp[i][j]);
        }
    }
    
    return result;
}

int main()
{
    vector<vector<char>> matrix;
    matrix.push_back(vector<char>{'1', '0', '1', '0', '0'});
    matrix.push_back(vector<char>{'1', '0', '1', '1', '1'});
    matrix.push_back(vector<char>{'1', '1', '1', '1', '1'});
    matrix.push_back(vector<char>{'1', '0', '0', '1', '0'});

    cout << maximalSquare(matrix) << endl;
    getchar();
}