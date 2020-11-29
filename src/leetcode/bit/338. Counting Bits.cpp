// https://leetcode.com/problems/counting-bits/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename T>
void printVector(vector<T> v)
{
    cout << "[";

    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            cout << v[i] << ", ";
        }
        else
        {
            cout << v[i] << "]" << endl;
        }
    }
}

vector<int> countBits(int num)
{
    static vector<int> dp(1, 0);

    while (dp.size() - 1 < num)
    {
        int t = dp.size();
        if ((t & 1) == 1)
        {
            // 奇数：二进制表示中，奇数一定比前面那个偶数多一个 1，因为多的就是最低位的 1。
            dp.push_back(dp[t - 1] + 1);
        }
        else
        {
            // 偶数：二进制表示中，偶数中 1 的个数一定和除以 2 之后的那个数一样多。因为最低位是 0，除以 2 就是右移一位，也就是把那个 0 抹掉而已，所以 1 的个数是不变的。
            dp.push_back(dp[t >> 1]);
        }
    }

    return vector<int>(dp.begin(), dp.begin() + num + 1);
}

int main()
{
    printVector<int>(countBits(2));
    printVector<int>(countBits(5));
    printVector<int>(countBits(10));

    getchar();
    return 0;
}