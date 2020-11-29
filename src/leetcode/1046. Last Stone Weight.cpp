// https://leetcode.com/problems/last-stone-weight/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int lastStoneWeight(vector<int> &stones)
{
    multiset<int> s(stones.begin(), stones.end());

    while (s.size() > 1)
    {
        auto w = *prev(s.end());
        s.erase(prev(s.end()));

        auto w2 = *prev(s.end());
        s.erase(prev(s.end()));

        if (w2 != w)
            s.insert(w - w2);
    }

    return s.empty() ? 0 : *s.begin();
}

int main()
{
    vector<int> a{2, 7, 4, 1, 8, 1};

    cout << lastStoneWeight(a) << endl;
    getchar();
    return 0;
}