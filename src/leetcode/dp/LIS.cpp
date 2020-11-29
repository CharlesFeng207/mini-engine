#include <algorithm>
#include <iostream>
#include <time.h>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename T>
void inner_combinations(T &v, int currentIndex, int currentDepth, int endingDepth, T &temp, vector<T> &result)
{
    if (currentDepth > endingDepth)
    {
        result.emplace_back(temp);
    }
    else
    {
        auto endingIndex = v.size() - temp.size() + currentDepth;
        for (auto i = currentIndex; i <= endingIndex; i++)
        {
            temp[currentDepth] = v[i];

            inner_combinations(v, i + 1, currentDepth + 1, endingDepth, temp, result);
        }
    }
}

template <typename T>
vector<T> combinations(T &v, int count)
{
    auto size = v.size();
    if (count > size)
        return {};

    vector<T> result;

    T t(count);
    inner_combinations(v, 0, 0, count - 1, t, result);

    return result;
}

template <typename T>
vector<T> combinations(string &v, int count)
{
    auto size = v.size();
    if (count > size)
        return {};

    vector<T> result;

    string t("", count);
    inner_combinations(v, 0, 0, count - 1, t, result);

    return result;
}

bool isLIS(vector<int> &combine)
{
    for (int i = 0; i < combine.size() - 1; i++)
    {
        if (combine[i + 1] < combine[i])
            return false;
    }

    return true;
}

// Not recommend
int lengthOfLIS_Combinations(vector<int> &nums)
{
    for (int i = nums.size(); i > 0; i--)
    {
        auto c = combinations(nums, i);
        if (any_of(c.begin(), c.end(), [](auto &t) {
                return isLIS(t);
            }))
        {
            return i;
        }
    }
    return 0;
}

// DP O(n^2)
int lengthOfLIS_DP(vector<int> &nums)
{
    int maxLen = 0;
    vector<int> dp(nums.size(), 0);

    for (int i = 0; i < nums.size(); i++)
    {
        int t = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                t = max(t, 1 + dp[j]);
            }
        }

        dp[i] = t;
        maxLen = max(maxLen, dp[i]);
    }

    return maxLen;
}

// O(nlogn)
int lengthOfLIS_Concise(vector<int> &nums)
{
    vector<int> helper;
    for (int i : nums)
    {
        auto it = lower_bound(helper.begin(), helper.end(), i);

        if (it == helper.end())
            helper.push_back(i);
        else
            *it = i;
    }
    return helper.size();
}

int main()
{
    // vector<int> nums = {-2, -1};
    // vector<int> nums = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 6};
    vector<int> nums;
    for (int i = 0; i < 10000; i++)
    {
        nums.push_back(rand());
    }

    auto t4 = clock();
    cout << "lengthOfLIS_Concise:" << lengthOfLIS_Concise(nums) << " " << clock() - t4 << endl;

    auto t2 = clock();
    cout << "lengthOfLIS_DP:" << lengthOfLIS_DP(nums) << " " << clock() - t2 << endl;

    auto t3 = clock();
    cout << "lengthOfLIS_Combinations:" << lengthOfLIS_Combinations(nums) << " " << clock() - t3 << endl;

    getchar();
}