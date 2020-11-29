// https://leetcode.com/problems/missing-number/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
#include <numeric>

using namespace std;

template <typename T>
void printVector(vector<T> &v)
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

int missingNumber(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size() + 1; // Missing one number
    return (n * (n - 1)) / 2 - sum;
}

int main()
{

    vector<int> a{9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << missingNumber(a) << endl;

    getchar();
    return 0;
}
