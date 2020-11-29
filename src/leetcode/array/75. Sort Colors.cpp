// https://leetcode.com/problems/3sum/

#include <algorithm>
#include <iostream>
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

void sortColors(vector<int> &nums)
{
    if (nums.size() < 2)
        return;

    int i = 0;
    int j = nums.size() - 1;

    for (int t = 0; t <= j; t++)
    {
        if (nums[t] == 0 && t > i)
        {
            swap(nums[i++], nums[t--]);
        }
        else if (nums[t] == 2 && t < j)
        {
            swap(nums[j--], nums[t--]);
        }
    }
}

int main()
{
    vector<int> a{2, 0, 2, 1, 2, 1, 1, 1, 0};
    // vector<int> a{2, 1};
    // vector<int> a{1, 2, 0};
    // vector<int> a{0, 0};
    auto c = clock();
    sortColors(a);
    cout << clock() - c << " ms" << endl;

    printVector<int>(a);

    getchar();

    return 0;
}