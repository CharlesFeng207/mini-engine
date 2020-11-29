// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
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

int removeDuplicates(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    
    // two pointers, j is the faster runner.
    int i = 0;
    for (int j = 1; j < nums.size(); j++)
    {
        if (nums[i] != nums[j])
        {
            nums[++i] = nums[j];
        }
    }

    return i + 1;
}

int main()
{
    vector<int> a{0, 1, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << removeDuplicates(a) << endl;
    printVector<int>(a);

    getchar();
    return 0;
}
