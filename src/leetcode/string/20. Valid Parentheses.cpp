// https://leetcode.com/problems/valid-parentheses/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool isValid(string s)
{
    static map<char, bool> table{{'(', true}, {')', false}, {'[', true}, {']', false}, {'{', true}, {'}', false}};
    stack<char> ps;

    for (int i = 0; i < s.size(); i++)
    {
        auto iter = table.find(s[i]);

        if (iter == table.end())
            return false;

        if (iter->second)
        {
            ps.push(iter->first);
        }
        else
        {
            if (ps.empty() || ps.top() != prev(iter)->first)
            {
                return false;
            }
            ps.pop();
        }
    }

    return ps.empty();
}

int main()
{
    cout << isValid("()([]{()})") << endl;
    cout << isValid("(]") << endl;
    getchar();
    return 0;
}
