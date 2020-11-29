// https://leetcode.com/problems/insert-delete-getrandom-o1

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class RandomizedSet
{
public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (m.find(val) != m.end())
            return false;

        v.push_back(val);
        m[val] = v.size() - 1;

        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (m.find(val) == m.end())
            return false;

        int last = v.back();
        
        m[last] = m[val];

        v[m[val]] = last;

        v.pop_back();
        m.erase(val);

        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        return v[rand() % v.size()];
    }

private:
    vector<int> v;
    unordered_map<int, int> m; // value -> index
};

int main()
{
    // Init an empty set.
    RandomizedSet randomSet;

    // Inserts 1 to the set. Returns true as 1 was inserted successfully.
    randomSet.insert(1);

    // Returns false as 2 does not exist in the set.
    randomSet.remove(2);

    // Inserts 2 to the set, returns true. Set now contains [1,2].
    randomSet.insert(2);

    // getRandom should return either 1 or 2 randomly.
    cout << randomSet.getRandom() << endl;

    // Removes 1 from the set, returns true. Set now contains [2].
    randomSet.remove(1);

    // 2 was already in the set, so return false.
    randomSet.insert(2);

    // Since 2 is the only number in the set, getRandom always return 2.
    cout << randomSet.getRandom() << endl;

    getchar();
    return 0;
}