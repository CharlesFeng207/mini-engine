// https://leetcode.com/problems/find-peak-element/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// O(n)
int findPeakElement_linear(vector<int> &nums)
{
    if (nums.size() < 2)
        return 0;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < nums[i - 1])
            return i - 1;
    }

    return nums.size() - 1;
}


// O(logN)
/*Most people have figured out the binary search solution but are not able to understand how its working. 
I will try to explain it simply. 
What we are essentially doing is going in the direction of the rising slope(by choosing the element which is greater than current). 
How does that guarantee the result? Think about it, there are 2 possibilities.
a) rising slope has to keep rising till end of the array 
b) rising slope will encounter a lesser element and go down.
In both scenarios we will have an answer. 
In a) the answer is the end element because we take the boundary as -INFINITY 
b) the answer is the largest element before the slope falls. 
Hope this makes things clearer. */
int findPeakElement(vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low < high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = mid1 + 1;
        if (nums[mid1] < nums[mid2])
            low = mid2;
        else
            high = mid1;
    }
    return low;
}

int main()
{
    vector<int> a{1, 2, 1, 3, 5, 6, 4};
    vector<int> b{1, 2, 3, 1};

    cout << findPeakElement(a);
    cout << endl;
    cout << findPeakElement(b);

    getchar();
    return 0;
}
