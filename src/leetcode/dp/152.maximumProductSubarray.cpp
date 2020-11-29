// https://leetcode.com/problems/maximum-product-subarray/

#include <algorithm>
#include <iostream>
#include <time.h>
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

// O(n^2)
int bruteforce(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    int result = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        int t = 1;
        for (int j = i; j >= 0; j--)
        {
            t *= nums[j];
            result = max(t, result);
        }
    }

    return result;
}

// O(n)
int maxProduct_dp(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    vector<int> dp_max(nums.size(), 0);
    vector<int> dp_min(nums.size(), 0);

    dp_max[0] = nums[0];
    dp_min[0] = nums[0];
    int result = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        int num = nums[i];
        dp_max[i] = max(max(dp_max[i - 1] * num, dp_min[i - 1] * num), num);
        dp_min[i] = min(min(dp_max[i - 1] * num, dp_min[i - 1] * num), num);

        result = max(result, dp_max[i]);
    }

    return result;
}

void test_case(vector<int> &nums)
{
    printVector<int>(nums);
    int t = clock();
    cout << "maxProduct_dp " << maxProduct_dp(nums) << " cost " << clock() - t << endl;
    t = clock();
    cout << "bruteforce " << bruteforce(nums) << " cost " << clock() - t << endl;
    cout << endl;
    cout << endl;
}

int main()
{
    vector<int> a{2, 3, -2, 4};
    test_case(a);

    vector<int> a2{-2, 0, -1};
    test_case(a2);

    vector<int> a3{-2};
    test_case(a3);

    vector<int> a4{-5, 2, 4, 1, -2, 2, -6, 3, -1, -1, -1, -2, -3, 5, 1, -3, -4, 2, -4, 6, -1, 5, -6, -1, -1, -1, -1};
    test_case(a4);

    vector<int> a5{3, -1, 4};
    test_case(a5);

    getchar();

    return 0;
}