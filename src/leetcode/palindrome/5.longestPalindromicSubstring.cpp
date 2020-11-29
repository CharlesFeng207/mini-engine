// https://leetcode.com/problems/longest-palindromic-substring/

#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include <unordered_map>
#include <vector>

using namespace std;

string to_manache_string(string &s, char c)
{
    string result(1, c);

    for (auto &sc : s)
        result += sc + string(1, c); // Char to string

    return result;
}

string longestPalindrome_manache(string s)
{
    if (s.size() == 0)
        return "";

    auto addChar = '#'; 
    auto str = to_manache_string(s, addChar);
    int size = str.size();

    vector<int> radius(size, 0);

    int maxLen = 0;
    int maxLenIndex = 0;

    int R = -1;
    int C = 0;

    for (int p1 = 0; p1 < size; p1++)
    {
        int p2 = max(0, 2 * C - p1); // p2 = C - (p1 - C)
        int C_left = max(0, C - radius[C]);
        int p2_left = max(0, p2 - radius[p2]);

        if (p1 > R || p2_left == C_left)
        {
            int i = 0;
            while (p1 + i < size && p1 - i >= 0 && str[p1 + i] == str[p1 - i])
            {
                radius[p1] = ++i;
            }

            C = p1;
        }
        else
        {
            if (p2_left > C_left)
            {
                radius[p1] = radius[p2];
            }
            else if (p2_left < C_left)
            {
                radius[p1] = C_left - p2_left + 1;
            }
        }

        if (radius[p1] > maxLen)
        {
            maxLen = radius[p1];
            maxLenIndex = p1;
        }
    }

    string result = "";
    for (int i = -maxLen + 1; i < maxLen; i++)
    {
        if (str[maxLenIndex + i] != addChar)
            result += str[maxLenIndex + i];
    }

    return result;
}

// more simple and fast than manache
string longestPalindrome_fast(string s)
{
    if (s.size() <= 1)
        return s;

    int min_start = 0, max_len = 1;
    for (int i = 0; i < s.size();)
    {
        if (s.size() - i <= max_len / 2) // Already doesn't have chance to beyond max len.
            break;

        int j = i;
        int k = i;

        while (k < s.size() - 1 && s[k + 1] == s[k])
            ++k; // Skip duplicate characters.

        // j is left bound, k is right bound
        i = k + 1;
        while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1])
        {
            ++k;
            --j;
        } // Expand.

        int new_len = k - j + 1;
        if (new_len > max_len)
        {
            min_start = j;
            max_len = new_len;
        }
    }

    return s.substr(min_start, max_len);
}

void test_case(string s, int n)
{
    cout << "test_case ------------- " << s << " x" << n << endl;

    string str;
    for (int i = 0; i < n; i++)
    {
        str += s;
    }

    int t = clock();
    cout << longestPalindrome_fast(str).size() << endl;
    cout << "fast " << clock() - t << " ms" << endl;

    int t2 = clock();
    cout << longestPalindrome_manache(str).size() << endl;
    cout << "manache " << clock() - t2 << " ms" << endl;

    cout << endl;
}

int main()
{
    test_case("xaaababaaahs", 3000);
    test_case("1a1a1a1a1a1a", 3000);

    getchar();
    return 0;
}