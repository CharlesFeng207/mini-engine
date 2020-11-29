// https://leetcode.com/problems/subsets/

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

void subset_inner(vector<int> &nums, int i, vector<int> &buffer, vector<vector<int>> &result)
{
    result.push_back(buffer);

    for (int j = i; j < nums.size(); j++)
    {
        buffer.push_back(nums[j]);
        subset_inner(nums, j + 1, buffer, result);
        buffer.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> result;

    vector<int> buffer;
    subset_inner(nums, 0, buffer, result);

    return result;
}

int main()
{
    // vector<int> a{1, 2, 3, 4};
    vector<int> a{1, 2, 3, 4};
    auto c = clock();

    auto t = subsets(a);
    cout << clock() - c << " ms" << endl;

    for (auto &v : t)
        printVector<int>(v);

    getchar();

    return 0;
}