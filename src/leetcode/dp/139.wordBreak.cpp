// https://leetcode.com/problems/word-break/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

bool wordBreak(string s, vector<string> &wordDict)
{
    if (wordDict.size() == 0)
        return false;

    unordered_set<string> dict(wordDict.begin(), wordDict.end());

    // dp[i] represent substr [0 -> i] is valid, so the answer is dp[n-1]
    // dp[i] = any dp[j] (j < i) exist, let substr [j + 1 -> i] is valid.
    vector<bool> dp(s.size(), false);

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i - 1; j >= -1; j--) // reverse loop of j is more efficient.
        {
            if (j == -1 || dp[j]) // j == -1 means the whole substr
            {
                string substr = s.substr(j + 1, i - j); // len = i - (j + 1) + 1
                if (dict.find(substr) != dict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
    }

    return dp[s.size() - 1];
}

int main()
{
    vector<string> a1{"leet", "code"};
    cout << wordBreak("leetcode", a1) << endl;

    vector<string> a2{"apple", "pen"};
    cout << wordBreak("applepenapple", a2) << endl;

    vector<string> a3{"cats", "dog", "sand", "and", "cat"};
    cout << wordBreak("catsandog", a3) << endl;

    getchar();
    return 0;
}