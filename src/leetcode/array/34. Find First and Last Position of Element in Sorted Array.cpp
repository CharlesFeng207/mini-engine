// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <algorithm>
#include <iostream>
#include <list>
#include <time.h>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while(right >= left)
    {
        int mid = (right + left) / 2;

        if(nums[mid] == target)
        {
            int range_start = mid, range_end = mid;
            while(range_start - 1 >= 0 && nums[range_start - 1] == target)
                range_start--;
            while(range_end + 1 < nums.size() && nums[range_end + 1] == target)
                range_end++;
            return {range_start, range_end};
        }
        else if(nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return {-1, -1};
}

int main()
{
    // vector<vector<int>> a{{1, 3}, {3, 6}, {8, 17}, {15, 18}};
    // 0 1 2 3 4 5
    vector<int> a{5, 7, 7, 8, 8, 10};
    auto b = searchRange(a, 6);

    for (auto &i : b)
    {
        cout << i << endl;
    }

    getchar();

    return 0;
}