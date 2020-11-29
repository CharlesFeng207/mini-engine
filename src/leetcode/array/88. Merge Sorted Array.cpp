// https://leetcode.com/problems/merge-sorted-array/

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

/*
The idea is to go from the last indexes of both arrays,
compare and put elements from either A or B to the final position, 
*/
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int a = m - 1;
    int b = n - 1;
    int i = m + n - 1; // calculate the index of the last element of the merged array

    // go from the back by A and B and compare and put to the A element which is larger
    while (a >= 0 && b >= 0)
    {
        if (nums1[a] > nums2[b])
            nums1[i--] = nums1[a--];
        else
            nums1[i--] = nums2[b--];
    }

    // if B is longer than A just copy the rest of B to A location, otherwise no need to do anything
    while (b >= 0)
        nums1[i--] = nums2[b--];
}

int main()
{

    vector<int> a1{1, 2, 3, 0, 0, 0, 0};
    vector<int> a2{0, 2, 5, 6};
    merge(a1, 3, a2, 4);

    printVector<int>(a1);

    getchar();
    return 0;
}
