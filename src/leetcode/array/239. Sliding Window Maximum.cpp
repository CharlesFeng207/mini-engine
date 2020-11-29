// https://leetcode.com/problems/sliding-window-maximum/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <deque>
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
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    if (nums.size() == 0)
        return {};

    multiset<int> win(nums.begin(), nums.begin() + k);
    vector<int> result{*prev(win.end())};

    for (int i = 0; i < nums.size() - k; i++)
    {
        auto iter = win.find(nums[i]);
        win.erase(iter);
        win.insert(nums[i + k]);
        result.push_back(*prev(win.end()));
    }

    return result;
}

vector<int> maxSlidingWindow_dequeue(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);
        
        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }
    return ans;

}
int main()
{
    // vector<int> a{1, 3, -1, -3, 5, 3, 6, 7};
    // auto t = maxSlidingWindow(a, 3);
    // printVector<int>(t);

    // vector<int> a2{7, 2, 4};
    // auto t = maxSlidingWindow(a2, 2);
    // printVector<int>(t);

    vector<int> a2{7, 7, 7, 6, 6};
    auto t = maxSlidingWindow(a2, 4);
    printVector<int>(t);

    getchar();
    return 0;
}