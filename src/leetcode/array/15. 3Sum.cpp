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

bool helper(vector<vector<int>> results, vector<int> t)
{

    // return true;
    for (auto &v : results)
    {
        if (v[0] == t[0] && v[1] == t[1] && v[2] == t[2])
            return false;
    }

    return true;
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    if (nums.size() < 3)
        return {};

    vector<vector<int>> results;
    unordered_map<int, vector<vector<int>>> cache;

    for (int i = 1; i < nums.size(); i++)
    {
        if (cache.find(nums[i]) != cache.end())
        {
            for (auto &v : cache[nums[i]])
            {
                vector<int> r{v[0], v[1], nums[i]};
                sort(r.begin(), r.end());

                if (helper(results, r))
                    results.emplace_back(r);
            }
        }

        for (int j = i - 1; j >= 0; j--)
        {
            int expect = -(nums[i] + nums[j]);
            if (cache.find(expect) == cache.end())
            {
                cache[expect] = vector<vector<int>>();
            }

            cache[expect].push_back({nums[i], nums[j]});
        }
    }

    return results;
}

// https://leetcode.com/problems/3sum/discuss/7402/Share-my-AC-C%2B%2B-solution-around-50ms-O(N*N)-with-explanation-and-comments
vector<vector<int>> threeSum2(vector<int> &num)
{
    vector<vector<int>> res;

    std::sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++)
    {
        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;

        while (front < back)
        {
            int sum = num[front] + num[back];

            // Finding answer which start from number num[i]
            if (sum < target)
                front++;
            else if (sum > target)
                back--;
            else
            {
                vector<int> triplet(3, 0);
                triplet[0] = num[i];
                triplet[1] = num[front];
                triplet[2] = num[back];
                
                res.push_back(triplet);

                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && num[front] == triplet[1])
                    front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && num[back] == triplet[2])
                    back--;
            }
        }

        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i])
            i++;
    }

    return res;
}

int main()
{
    vector<int> a{-1, 0, 1, 2, -1, -4, -1, 0, 1, 2, -1, -4, -1, 0, 1, 2, -1, -4};

    auto c = clock();
    // vector<int> a{4, 4, 6, -1, 10, 9, -8, 7, -13, 14, -13, -11, -8, -9, 11, 14, -8, -14, -13, 7, -10, -15, -13, -11, -11, 11, 14, 13, 2, -14, 1, -7, -2, 14, -1, -15, 9, 7, -1, 3, 6, 1, 7, 5, -1, -5, 4, -2, -4, -1, -9, -7, -1, -7, -11, 3, 12, 10, -7, -1, 12, 1, 8, -13, 1, 14, 9, -13, 6, -7, -3, -11, 2, -11, 10, -14, -1, -9, 0, 2, 5, 6, 3, -11, 6, 7, 0, 3, 3, 0, -12, -8, -13, 3, -14, -5, 2, 10, -11, -14, -12, 1, -10, 5, 5, 7, -1, 11, 14, 6, -10, -4, -3, 8, -7, 10, 1, 8, -1, -11, -15, -6, -12, -13, 12, -11};
    auto t = threeSum2(a);
    cout << clock() - c << " ms" << endl;

    for (auto &v : t)
    {
        printVector<int>(v);
    }

    getchar();

    return 0;
}