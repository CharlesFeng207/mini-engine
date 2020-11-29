// https://leetcode.com/problems/decode-ways/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numDecodings_wrong(string s)
{
    if (s.size() == 0)
        return 0;

    // illegal input
    if (s[0] == '0')
        return 0;

    // dp[i] represent how many ways that a character end with s[i-1]
    // so the answer is dp[s.size()]
    vector<int> dp(s.size() + 1);

    dp[0] = 0;
    dp[1] = s[0] != '0' ? 1 : 0;

    for (int i = 2; i <= s.size(); i++)
    {
        // i - 1 means independent slicing
        // i - 2 means dependent slicing
        switch (s[i - 1])
        {
        case '0':                                   // must be dependent, end with i - 2
            if (s[i - 2] != '1' && s[i - 2] != '2') // illegal input
                return 0;
            dp[i] = dp[i - 2];
            break;
        case '7':
        case '8':
        case '9': // must be independent, end with i - 1
            dp[i] = dp[i - 1];
            break;
        default:

            
            dp[i] = dp[i - 2] + dp[i - 1];

            break;
        }
    }

    return dp[s.size()];
}

// dp O(n)
int numDecodings(string s)
{
    if (s.size() == 0)
        return 0;

    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;
    dp[1] = s[0] != '0' ? 1 : 0;

    for (int i = 2; i <= s.size(); i++)
    {
        int first = stoi(s.substr(i - 1, 1));
        int second = stoi(s.substr(i - 2, 2));

        if (first >= 1 && first <= 9)
        {
            dp[i] += dp[i - 1];
        }

        if (second >= 10 && second <= 26)
        {
            dp[i] += dp[i - 2];
        }
    }

    return dp[s.size()];
}

int main()
{
    cout << numDecodings("226") << endl; // 3
    cout << numDecodings("220") << endl; // 1
    cout << numDecodings("227") << endl; // 2
    string s = "6065812287883668764831544958683283296479682877898293612168136334983851946827579555449329483852397155";
    cout << numDecodings(s) << endl; // 0
    string s2 = "4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948";
    cout << numDecodings(s2);             // 5898240
    cout << numDecodings("0") << endl;    // 0
    cout << numDecodings("100") << endl;  // 0
    cout << numDecodings("101") << endl;  // 1
    cout << numDecodings("10") << endl;   // 1
    cout << numDecodings("1010") << endl; // 1
    getchar();
    return 0;
}