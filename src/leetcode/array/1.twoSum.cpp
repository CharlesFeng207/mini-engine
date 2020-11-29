// https://leetcode.com/problems/two-sum/

#include <algorithm>
#include <iostream>
#include <time.h>
#include <unordered_map>
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

// O(n^2)
vector<int> twoSum(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return vector<int>{i, j};
            }
        }
    }

    return {};
}

// O(n)
vector<int> twoSum_Fast(vector<int> &nums, int target)
{
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++)
    {
        auto iter = map.find(nums[i]);

        if (iter != map.end())
        {
            return vector<int>{iter->second, i};
        }
        else
        {
            int mate = target - nums[i];
            map[mate] = i;
        }
    }

    return {};
}

int main()
{
    vector<int> a{2, 7, 11, 15};
    auto t = twoSum_Fast(a, 9);
    printVector<int>(t);

    getchar();

    return 0;
}