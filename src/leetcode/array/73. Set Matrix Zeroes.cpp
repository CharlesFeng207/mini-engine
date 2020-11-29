// https://leetcode.com/problems/set-matrix-zeroes/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    if (matrix.size() == 0)
        return;

    vector<bool> row_zero(matrix.size(), false);
    vector<bool> col_zero(matrix[0].size(), false);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                row_zero[i] = true;
                col_zero[j] = true;
            }
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (row_zero[i] || col_zero[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}

int main()
{
    // vector<vector<int>> a{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> a{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    setZeroes(a);

    for (auto &v : a)
    {
        for (auto &i : v)
        {
            cout << i;
        }

        cout << endl;
    }

    getchar();
    return 0;
}
