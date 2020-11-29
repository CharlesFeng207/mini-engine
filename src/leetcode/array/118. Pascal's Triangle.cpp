// https://leetcode.com/problems/pascals-triangle/

#include <algorithm>
#include <iostream>
#include <time.h>
#include <unordered_map>
#include <vector>

using namespace std;
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> result;
    for (int i = 0; i < numRows; i++)
    {
        result.emplace_back(i + 1, 0);
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
                result[i][j] = 1;
            else
                result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
        }
    }

    return result;
}

int main()
{
    auto a = generate(5);

    for (auto &row : a)
    {
        for (auto &col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    getchar();

    return 0;
}