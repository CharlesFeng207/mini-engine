// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// O(n)
int maxProfit(vector<int> &prices)
{
    if (prices.size() < 2)
        return 0;

    // The maximum profit can be made if the first i days end with buy or wait.
    // E.g "buy, sell, buy" or "buy, cooldown, cooldown"
    vector<int> dp_buy(prices.size());
    dp_buy[0] = -prices[0];
    dp_buy[1] = max(dp_buy[0], -prices[1]);

    //The maximum profit can be made if the first i days end with sell or wait.
    //E.g "buy, sell, buy, sell" or "buy, sell, cooldown, cooldown"
    vector<int> dp_sell(prices.size());
    dp_sell[0] = 0;
    dp_sell[1] = max(dp_sell[0], dp_buy[0] + prices[1]);

    for (int i = 2; i < prices.size(); i++)
    {
        // Cool down, same with dp_buy[i - 1]
        // Buy,  dp_sell[i - 2] - prices[i], because we have to cool down after sell.
        dp_buy[i] = max(dp_buy[i - 1], dp_sell[i - 2] - prices[i]);

        // Cool down, same with dp_sell[i - 1]
        // Sell, dp_buy[i - 1] + prices[i]
        dp_sell[i] = max(dp_sell[i - 1], dp_buy[i - 1] + prices[i]);
    }

    // dp_sell[prices.size() - 1] is definitely bigger than dp_buy[prices.size() - 1]
    return dp_sell[prices.size() - 1];
}

int main()
{
    // vector<int> a{7, 1, 5, 3, 6, 4, 0, 1, 9};
    vector<int> a{1, 2, 3, 0, 2};
    cout << maxProfit(a) << endl;
    getchar();
    return 0;
}