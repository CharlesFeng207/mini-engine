// https://leetcode.com/problems/plus-one/

#include <algorithm>
#include <iostream>
#include <list>
#include <time.h>
#include <unordered_map>
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

vector<int> plusOne(vector<int> &digits)
{
    if (digits.size() == 0)
        return {};

    if (digits.back() != 9)
    {
        digits.back() += 1;
        return digits;
    }

    list mylist(digits.begin(), digits.end());

    auto t = prev(mylist.end());

    while (true)
    {
        if (*t != 9)
        {
            *t += 1;
            break;
        }

        *t = 0;

        if (t == mylist.begin())
        {
            mylist.push_front(0);
        }
        t--;
    }

    return vector<int>(mylist.begin(), mylist.end());
}

vector<int> plusone_simple(vector<int> &digits)
{
    int n = digits.size();
    for (int i = n - 1; i >= 0; --i)
    {
        if (digits[i] == 9)
        {
            digits[i] = 0;
        }
        else
        {
            digits[i]++;
            return digits;
        }
    }

    digits[0] = 1;
    digits.push_back(0);
    return digits;
}

int main()
{
    vector<int> a{9, 9, 9, 1};
    auto t = plusOne(a);
    printVector<int>(t);

    getchar();

    return 0;
}