#include <algorithm>
#include <iostream>
#include <time.h>
#include <unordered_map>
#include <vector>

using namespace std;

int countSubstrings(string s)
{
    int size = s.size();
    if (size <= 1)
        return size;

    int count = size;

    for (int i = 0; i < size;)
    {
        int right = i;

        int n = 0;
        while (right < size - 1 && s[right + 1] == s[right])
        {
            n++;
            right++; // skip duplicated characters.
        }

        int left = i;

        count += n + n * (n - 1) / 2;

        i = right + 1;
        while (right < size - 1 && left > 0 && s[right + 1] == s[left - 1])
        {
            right++;
            left--;
            count++;
        }
    }

    return count;
}

int main()
{
    cout << countSubstrings("abc") << endl;
    cout << countSubstrings("aaa") << endl;
    getchar();
}