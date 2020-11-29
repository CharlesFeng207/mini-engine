// https://leetcode.com/problems/first-unique-character-in-a-string/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool isDuplicate(char a, string &s, int start)
{
    for (int i = start; i < s.size(); i++)
    {
        if (s[i] == a)
            return true;
    }

    return false;
}

int firstUniqChar(string s)
{
    int bitSet = 0;

    for (int i = 0; i < s.size(); i++)
    {
        int order = 1 << (s[i] - 'a');

        if (bitSet & order)
            continue;

        if (isDuplicate(s[i], s, i + 1))
        {
            bitSet |= order;
        }
        else
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    cout << firstUniqChar("leetcode") << endl;
    cout << firstUniqChar("loveleetcode") << endl;
    cout << firstUniqChar("asdssda") << endl;
    getchar();
    return 0;
}
