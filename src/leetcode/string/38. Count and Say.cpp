// https://leetcode.com/problems/count-and-say/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string countAndSay(int n)
{
    static vector<string> cache{"", "1"};

    while (cache.size() < n + 1)
    {
        int p = cache.size();
        auto lastStr = cache[p - 1] + "*";

        int curCount = 0;
        char curChar = '*';
        string str;

        for (int i = 0; i < lastStr.size(); i++)
        {
            if (curChar != lastStr[i])
            {
                if (curCount > 0)
                {
                    str += (to_string(curCount) + string(1, curChar)); // Char to string
                }

                curCount = 1;
                curChar = lastStr[i];
            }
            else
            {
                curCount++;
            }
        }

        cache.push_back(str);
    }

    return cache[n];
}

int main()
{
    cout << countAndSay(1) << endl;
    cout << countAndSay(4) << endl;
    getchar();
    return 0;
}
