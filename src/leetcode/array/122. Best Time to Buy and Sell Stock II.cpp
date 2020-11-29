// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int maxProfit_dp(vector<int> &prices)
{
    if (prices.size() == 0)
        return 0;

    vector<int> dp_buy(prices.size(), 0);
    dp_buy[0] = -prices[0];

    vector<int> dp_sell(prices.size(), 0);
    dp_sell[0] = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        dp_buy[i] = max(dp_buy[i - 1], dp_sell[i - 1] - prices[i]);
        dp_sell[i] = max(dp_sell[i - 1], dp_buy[i - 1] + prices[i]);
    }

    return dp_sell.back();
}

int maxProfit(vector<int> &prices)
{
    if (prices.size() == 0)
        return 0;

    int ret = 0;
    for (int i = 1; i < prices.size(); ++i)
        ret += max(prices[i] - prices[i - 1], 0);
        
    return ret;
}

int main()
{
    // vector<int> a{7, 1, 5, 3, 6, 4, 0, 1, 9};
    vector<int> a{7, 1, 5, 3, 6, 4};
    cout << maxProfit_dp(a) << endl;
    cout << maxProfit(a) << endl;
    getchar();
    return 0;
}