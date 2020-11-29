#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include <unordered_map>
#include <vector>

using namespace std;

int LPS_inner_recursive(string &s, int start, int end, vector<vector<int>> &P)
{
    if (start == end)
        return 1;
    else if (end < start)
        return 0;

    if (P[start][end] == 0)
    {
        if (s[start] == s[end])
        {
            P[start][end] = LPS_inner_recursive(s, start + 1, end - 1, P) + 2;
        }
        else
        {
            P[start][end] = max(LPS_inner_recursive(s, start + 1, end, P), LPS_inner_recursive(s, start, end - 1, P));
        }
    }

    return P[start][end];
}

int LPS_recursive(string &s)
{
    if (s.size() < 1)
        return s.size();

    vector<vector<int>> P(s.size(), vector<int>(s.size()));
    return LPS_inner_recursive(s, 0, s.size() - 1, P);
}

int LPS_dp(string &s)
{
    if (s.size() < 2)
        return s.size();

    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

    for (int i = s.size() - 1; i >= 0; i--)
    {
        for (int j = i; j < s.size(); j++)
        {
            if (j == i)
            {
                dp[i][j] = 1;
            }
            else
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
    }

    return dp[0][s.size() - 1];
}

int main()
{
    string s("CAAcBAADCDFFF");
    cout << LPS_recursive(s) << endl;
    cout << LPS_dp(s) << endl;

    getchar();
    return 0;
}