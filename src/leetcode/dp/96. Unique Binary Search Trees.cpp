#include <algorithm>
#include <iostream>
#include <time.h>
#include <unordered_map>
#include <vector>

using namespace std;

int numTrees(int n)
{
    if (n < 1)
        return 0;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int si = 0; si < i; si++)
        {
            dp[i] += dp[si] * dp[i - si - 1];
        }
    }

    return dp[n];
}

int main()
{
    cout << numTrees(3) << endl;
    getchar();
}