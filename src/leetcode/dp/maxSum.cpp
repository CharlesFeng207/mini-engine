// https://blog.csdn.net/baidu_28312631/article/details/47418773

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxSum(vector<vector<int>> &a, int rowIndex, int colIndex)
{
    static vector<vector<int>> cache(a.size(), vector<int>(a.size(), -1));

    if (cache[rowIndex][colIndex] != -1)
    {
        return cache[rowIndex][colIndex];
    }
    else
    {
        if (rowIndex == a.size() - 1)
        {
            return a[rowIndex][colIndex];
        }
        else
        {
            int left = a[rowIndex][colIndex] + maxSum(a, rowIndex + 1, colIndex);
            int right = a[rowIndex][colIndex] + maxSum(a, rowIndex + 1, colIndex + 1);
            int result = max(left, right);
            cache[rowIndex][colIndex] = result;
            return result;
        }
    }
}

int maxSum_dp(vector<vector<int>> &a, int rowIndex, int colIndex)
{
    vector<vector<int>> dp(a.size(), vector<int>(a.size(), 0));

    for (int i = a.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == a.size() - 1)
            {
                dp[i][j] = a[i][j];
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j];
            }
        }
    }

    return dp[rowIndex][colIndex];
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

    cout << "maxSum:" << maxSum(a, 0, 0) << endl;
    cout << "maxSum_dp:" << maxSum_dp(a, 0, 0) << endl;

    getchar();
}