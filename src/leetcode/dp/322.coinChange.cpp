// https://leetcode.com/problems/coin-change/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <time.h>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename T>
void printVector(vector<T> &v)
{
    cout << "[";

    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            cout << v[i] << ", ";
        }
        else
        {
            cout << v[i] << "]" << endl;
        }
    }
}

int coinChange_dp(vector<int> &coins, int amount)
{
    if (amount <= 0)
        return 0;

    if (coins.size() == 0)
        return -1;

    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (auto &coin : coins)
        {
            if (coin > i)
                continue;

            dp[i] = min(dp[i], dp[i - coin] + 1); // when i == coin, dp[coin] == 1
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}

void test_case(vector<int> &coins, int amount)
{
    int t = clock();
    printVector<int>(coins);
    cout << "amount: " << amount << endl;
    cout << "dp: " << coinChange_dp(coins, amount) << " cost " << clock() - t << "ms" << endl;
    cout << "end" << endl;
    cout << endl;
}

int main()
{
    vector<int> a1{1, 5, 2};
    test_case(a1, 11);

    vector<int> a2{2};
    test_case(a2, 1);
    test_case(a2, 3);

    vector<int> a3{1, 2147483647};
    test_case(a3, 2);

    vector<int> a4{3, 7, 405, 436};
    test_case(a4, 8839);

    vector<int> a5{261, 411, 27, 78, 61};
    test_case(a5, 5456);

    vector<int> a6{436, 83, 210, 75, 286};
    test_case(a6, 3165);

    vector<int> a7{474, 83, 404, 3};
    test_case(a7, 264);

    getchar();

    return 0;
}