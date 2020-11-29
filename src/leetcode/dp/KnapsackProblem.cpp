// http://www.csie.ntnu.edu.tw/~u91029/KnapsackProblem.html
// https://www.jianshu.com/p/2638e1111b9e

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <time.h>
#include <unordered_map>
#include <vector>

using namespace std;

void print_dp(vector<vector<int>> &dp)
{
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[i].size(); j++)
        {
            cout << setw(4) << dp[i][j] << "";
        }
        cout << endl;
    }
    cout << endl;
}

int knapsack(vector<int> &prices, vector<int> &weight, int n, int w)
{
    // dp[i][j]: i means how many items avaible, j means how many weight avalible
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (j < weight[i - 1]) // Cautions: weight && prices index starts at 0.
            {
                // no weight avalible for this item
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                // two choice
                // 1.don't put 2.put, select maximum one then save
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + prices[i - 1]);
            }
        }
    }

    print_dp(dp);
    return dp[n][w];
}

int main()
{
    vector<int> prices{1, 7, 23, 16, 32};
    vector<int> weight{1, 3, 4, 6, 8};
    cout << knapsack(prices, weight, prices.size(), 12) << endl;
    getchar();
    return 0;
}