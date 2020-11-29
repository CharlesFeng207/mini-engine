// https://leetcode.com/problems/find-the-duplicate-number/

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

/*
index	[0]	[1]	[2]	[3]	[4]	[5]	[6]
value	 2	 6	 4	 1	 3	 1	 5
linked list with cycle:
index	[0]	[2]	[4]	[3]	[1]	[6]
value	 2-> 4-> 3-> 1-> 6-> 5 
became question "142. Linked List Cycle II" from here.
 */
int findDuplicate(vector<int> &nums)
{
    int slow = 0;
    int fast = 0;
    while (true)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast)
            break;
    }
    slow = 0;
    while (fast != slow)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main()
{
    // vector<int> a{2, 2, 2, 2, 2};
    // vector<int> a{1, 4, 4, 2, 4};
    vector<int> a{1, 4, 2, 3, 2};
    auto c = clock();

    auto t = findDuplicate(a);
    cout << clock() - c << " ms" << endl;

    cout << t << endl;

    getchar();

    return 0;
}