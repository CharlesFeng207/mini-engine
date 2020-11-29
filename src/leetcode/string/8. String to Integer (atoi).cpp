// https://leetcode.com/problems/string-to-integer-atoi/

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

int myAtoi(string str)
{
    long result = 0;
    int indicator = 1;

    int i = str.find_first_not_of(' ');
    if (i == -1)
        return 0;

    if (str[i] == '-' || str[i] == '+')
        indicator = (str[i++] == '-') ? -1 : 1;

    while ('0' <= str[i] && str[i] <= '9')
    {
        result = result * 10 + (str[i++] - '0');
        if (result * indicator >= INT_MAX)
            return INT_MAX;
        if (result * indicator <= INT_MIN)
            return INT_MIN;
    }

    return result * indicator;
}

int main()
{
    cout << myAtoi("  ") << endl;
    cout << myAtoi(" -546") << endl;
    getchar();
    return 0;
}
