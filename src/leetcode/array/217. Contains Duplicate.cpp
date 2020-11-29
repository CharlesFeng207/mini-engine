// https://leetcode.com/problems/contains-duplicate/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>

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

// time:O(n) space:O(n)
bool containsDuplicate(vector<int> &nums)
{
    return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size();
}

int main()
{
    vector<int> a{1, 2, 3, 1};
    cout << containsDuplicate(a) << endl;

    getchar();
    return 0;
}
