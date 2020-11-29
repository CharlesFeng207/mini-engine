// https://leetcode.com/problems/rotate-array/

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
void rotate(vector<int> &nums, int k)
{
    int size = nums.size();
    int k2 = k % size;
    vector<int> nums2 = nums;
    for (int i = 0; i < size; i++)
    {
        int j = (i - k2 + size) % size;
        nums[i] = nums2[j];
    }
}

/*
Think about shifting array [1,2,3,4,5] by k=2:
1,2,3,4,5 -> 4,5,1,2,3
If you observe, what we did is: swap left & right sub arrays, where right sub has len=k
(1,2,3),(4,5) -> (4,5),(1,2,3)
*/

// time: O(n) space:O(1)
void rotate_reverse(vector<int> &nums, int k)
{
    int size = nums.size();
    int k2 = k % size;

    reverse(nums.end() - k2, nums.end());
    reverse(nums.begin(), nums.end() - k2);
    reverse(nums.begin(), nums.end());
}

int main()
{
    vector<int> a{1, 2, 3, 4, 5, 6, 7};
    rotate(a, 3);
    printVector<int>(a);

    vector<int> a2{1, 2, 3, 4, 5, 6, 7};
    rotate_reverse(a2, 3);
    printVector<int>(a2);

    getchar();
    return 0;
}
