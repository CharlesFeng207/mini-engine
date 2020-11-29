// https://leetcode.com/problems/majority-element/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

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
int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> map;

    for (auto &n : nums)
    {
        if (map.find(n) == map.end())
            map[n] = 0;

        map[n] += 1;

        //  assume that the array is non-empty and the majority element always exist in the array.
        if (map[n] > nums.size() / 2)
            return n;
    }

    return 0;
}

// time:O(n) space:O(1)
int majorityElement_dp_like(vector<int> &nums)
{
    // assume that the array is non-empty
    int major = nums[0];
    int count = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (count == 0)
        {
            major = nums[i];
            count = 1;
        }
        else if (nums[i] == major)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    return major;
}

int main()
{
    vector<int> a{3, 3, 3, 4, 4, 4, 3, 3, 2};
    cout << majorityElement(a) << endl;

    cout << majorityElement_dp_like(a) << endl;

    getchar();
    return 0;
}
