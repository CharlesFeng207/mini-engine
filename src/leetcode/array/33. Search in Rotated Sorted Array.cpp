// https://leetcode.com/problemset/top-interview-questions/?topicSlugs=array

#include <algorithm>
#include <iostream>
#include <list>
#include <time.h>
#include <unordered_map>
#include <vector>

using namespace std;

int findk(vector<int> &nums)
{
    int left = 0;
    int right = nums.size() - 1;

    int t = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] >= nums[0])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
            t = mid;
        }
    }

    return t;
}

int search(vector<int> &nums, int target)
{
    int k = findk(nums);

    int size = nums.size();

    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int mid_k = (mid + k) % size;
        int value = nums[mid_k];
        if (value == target)
        {
            return mid_k;
        }
        else if (value > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return -1;
}

int main()
{

    // vector<int> a{3, 4, 5, 6, 7, 0, 1, 2};
    vector<int> a{3, 1};

    for (int i = 0; i < a.size(); i++)
    {
        cout << search(a, a[i]) << endl;
    }
    cout << search(a, 99) << endl;

    getchar();

    return 0;
}