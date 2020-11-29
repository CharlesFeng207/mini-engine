// https://leetcode.com/problems/merge-intervals/

#include <algorithm>
#include <iostream>
#include <list>
#include <time.h>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.empty())
        return {};
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) { return a[0] < b[0]; });
    res.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (res.back()[1] < intervals[i][0])
            res.push_back(intervals[i]);
        else
            res.back()[1] = max(res.back()[1], intervals[i][1]);
    }
    return res;
}

int main()
{
    // vector<vector<int>> a{{1, 3}, {3, 6}, {8, 17}, {15, 18}};
    // 0 1 2 3 4 5
    vector<vector<int>> a{{1, 4}, {0, 2}, {3, 5}};
    auto b = merge(a);

    for (auto &v : b)
    {
        cout << v[0] << " -> " << v[1] << endl;
    }

    getchar();

    return 0;
}