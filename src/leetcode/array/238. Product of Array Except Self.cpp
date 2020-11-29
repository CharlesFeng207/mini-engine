// https://leetcode.com/problems/product-of-array-except-self/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename T>
void printVector(vector<T> &vector)
{
    cout << "[";

    int size = vector.size();
    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            cout << vector[i] << ", ";
        }
        else
        {
            cout << vector[i] << "]" << endl;
        }
    }
}

vector<int> productExceptSelf(vector<int> &nums)
{
    if (nums.size() == 0)
        return {};

    vector<int> result(nums.size(), 0);

    int p = 1;
    int zero_count = 0; // Caution: nums[i] may be zero
    int zero_index;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            zero_count++;
            if (zero_count > 1)
                return result;

            zero_index = i;
        }
        else
        {
            p *= nums[i];
        }
    }

    if (zero_count == 1)
    {
        result[zero_index] = p;
        return result;
    }

    p /= nums[0];
    result[0] = p;

    for (int i = 1; i < nums.size(); i++)
    {
        p = p / nums[i] * nums[i - 1];
        result[i] = p;
    }

    return result;
}

int main()
{
    // vector<int> a{1, 2, 3, 4};
    vector<int> a{0, 1};
    auto c = clock();

    auto t = productExceptSelf(a);
    cout << clock() - c << " ms" << endl;

    printVector<int>(t);

    getchar();

    return 0;
}