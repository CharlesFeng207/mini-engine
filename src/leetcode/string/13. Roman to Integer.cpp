// https://leetcode.com/problems/roman-to-integer/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string intToRoman(int num)
{
    static map<int, string> v = {{1, "I"},
                                 {4, "IV"},
                                 {5, "V"},
                                 {9, "IX"},
                                 {10, "X"},
                                 {40, "XL"},
                                 {50, "L"},
                                 {90, "XC"},
                                 {100, "C"},
                                 {400, "CD"},
                                 {500, "D"},
                                 {900, "CM"},
                                 {1000, "M"}};

    int total = num;
    string result = "";
    while (total > 0)
    {
        auto iter = v.end();
        do
        {
            iter--;
            if (total >= iter->first)
            {
                total -= iter->first;
                result += iter->second;
                break;
            }

        } while (iter != v.begin());
    }

    return result;
}

int romanToInt(string s)
{
    if (s.size() == 0)
        return 0;

    static unordered_map<char, int> v = {{'I', 1},
                                         {'V', 5},
                                         {'X', 10},
                                         {'L', 50},
                                         {'C', 100},
                                         {'D', 500},
                                         {'M', 1000}};

    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int a = v[s[i]];
        int b = i == s.size() - 1 ? 0 : v[s[i + 1]];
        if (a < b)
        {
            sum -= a;
        }
        else
        {
            sum += a;
        }
    }

    return sum;
}

int main()
{

    cout << romanToInt("MCMXCIV") << endl;
    cout << intToRoman(1994) << endl;

    getchar();
    return 0;
}
