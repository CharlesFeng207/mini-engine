// https://leetcode.com/problems/reverse-string/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename T>
void printVector(vector<T> &v)
{
    cout << "[";

    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            cout << v[i] << ", ";
        }
        else
        {
            cout << v[i] << "]" << endl;
        }
    }
}

void reverseString(vector<char> &s)
{
    if (s.size() < 2)
        return;

    int last = s.size() - 1;
    int half = last / 2;

    for (int i = 0; i <= half; i++)
    {
        swap(s[i], s[last - i]);
    }
}

int main()
{

    vector<char> a{'h', 'e', 'l', 'l', 'o'};
    reverseString(a);
    printVector<char>(a);

    getchar();
    return 0;
}
