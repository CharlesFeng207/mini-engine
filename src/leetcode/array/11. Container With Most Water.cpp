// https://leetcode.com/problems/container-with-most-water/

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
Start by evaluating the widest container, using the first and the last line.
All other possible containers are less wide, so to hold more water, they need to be higher. Thus, after evaluating that widest container, skip lines at both ends that don't support a higher height. 
Then evaluate that new container we arrived at. Repeat until there are no more possible containers left.
 */
int maxArea(vector<int> &height)
{
    int water = 0;
    int i = 0, j = height.size() - 1;
    while (i < j)
    {
        int h = min(height[i], height[j]);
        water = max(water, (j - i) * h);
        while (height[i] <= h && i < j)
            i++;
        while (height[j] <= h && i < j)
            j--;
    }
    return water;
}

int main()
{

    vector<int> a{1, 8, 6, 2, 5, 4, 8, 3, 7};
    auto c = clock();

    auto t = maxArea(a);
    cout << clock() - c << " ms" << endl;

    cout << t << endl;

    getchar();

    return 0;
}