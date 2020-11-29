// https://leetcode.com/problems/move-zeroes/

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

// time: O(n) space:O(n)
void moveZeroes(vector<int> &nums)
{
    if (nums.size() == 0)
        return;

    vector<int> nums2(nums.size(), 0);

    int j = 0;
    for (auto &n : nums)
    {
        if (n != 0)
            nums2[j++] = n;
    }

    nums = nums2;
}

// time: O(n * logn) space:O(1)
void moveZeroes_quick_sort(vector<int> &nums)
{
    if (nums.size() == 0)
        return;

    sort(nums.begin(), nums.end(), [](auto &a, auto &b) {
        return b == 0;
    });
}

// time:O(n) space:O(1)， the fastest approach
void moveZeroes_in_place(vector<int> &nums)
{
    // two pointers, j is the faster runner. j must start with 0
    int i = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] != 0)
            swap(nums[j], nums[i++]);
    }
}

int main()
{
    vector<int> a{1, 1, 1, 0, 1};
    moveZeroes(a);
    printVector<int>(a);

    vector<int> a2{0, 1, 0, 3, 12};
    moveZeroes_quick_sort(a2);
    printVector<int>(a2);

    vector<int> a3{0, 1, 0, 3, 12};
    moveZeroes_in_place(a3);
    printVector<int>(a3);

    vector<int> a4{1, 1, 1, 0, 1};
    moveZeroes_in_place(a4);
    printVector<int>(a4);

    getchar();
    return 0;
}
