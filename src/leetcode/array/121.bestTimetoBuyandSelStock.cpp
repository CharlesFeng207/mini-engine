// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


// O(n^2)
int maxProfit(vector<int> &prices)
{
    int profit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i + 1; j < prices.size(); j++)
        {
            profit = max(profit, prices[j] - prices[i]);
        }
    }

    return profit;
}

// O(n)
int maxProfit_fast(vector<int> &prices)
{
    if(prices.size() == 0)
        return 0;

    int profit = 0;
    int minPrice = prices[0];
    
    for (int i = 1; i < prices.size(); i++)
    {
        minPrice = min(minPrice, prices[i]);
        profit = max(prices[i] - minPrice, profit);
    }

    return profit;
}

int main()
{
    // vector<int> a{7, 1, 5, 3, 6, 4, 0, 1, 9};
    vector<int> a{7, 1, 5, 3, 6, 4};
    cout << maxProfit(a) << endl;
    cout << maxProfit_fast(a) << endl;
    getchar();
    return 0;
}