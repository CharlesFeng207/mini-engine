// https://leetcode.com/problems/spiral-matrix/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <time.h>
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

void collect(int startY, int startX, int m, int n, vector<vector<int>> &matrix, vector<int> &result)
{
    for (int x = startX; x < startX + n; x++)
    {
        result.push_back(matrix[startY][x]);
    }

    if (m == 1)
        return;

    for (int y = startY + 1; y < startY + m; y++)
    {
        result.push_back(matrix[y][startX + n - 1]);
    }

    if (n == 1)
        return;

    for (int x = startX + n - 2; x >= startX; x--)
    {
        result.push_back(matrix[startY + m - 1][x]);
    }

    for (int y = startY + m - 2; y >= startY + 1; y--)
    {
        result.push_back(matrix[y][startX]);
    }
}

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    if (m == 0)
        return {};
    if (m == 1)
        return matrix[0];

    int n = matrix[0].size();
    vector<int> result;

    for (int i = 0; i < ceil(m / 2.0) && i < ceil(n / 2.0); i++)
    {
        collect(i, i, m - 2 * i, n - 2 * i, matrix, result);
    }

    return result;
}

vector<int> spiralOrder_consise(vector<vector<int>> &matrix)
{
    vector<int> res;
    if (matrix.size() == 0)
        return res;
    int m = matrix.size(), n = matrix[0].size();
    int up = 0, down = m - 1;
    int left = 0, right = n - 1;
    while (res.size() < n * m)
    {
        for (int j = left; j <= right && res.size() < n * m; j++)
            res.push_back(matrix[up][j]);

        for (int i = up + 1; i <= down - 1 && res.size() < n * m; i++)
            res.push_back(matrix[i][right]);

        for (int j = right; j >= left && res.size() < n * m; j--)
            res.push_back(matrix[down][j]);

        for (int i = down - 1; i >= up + 1 && res.size() < n * m; i--)
            res.push_back(matrix[i][left]);

        left++;
        right--;
        up++;
        down--;
    }
    return res;
}

int main()
{
    int m = 5;
    int n = 5;

    vector<vector<int>> matrix;
    int c = 0;
    for (int i = 0; i < m; i++)
    {
        vector<int> t;
        for (int j = 0; j < n; j++)
        {
            t.push_back(c);
            cout << setw(3) << c << " ";
            c++;
        }
        matrix.push_back(t);
        cout << endl;
    }

    // vector<vector<int>> matrix{{3}, {2}};
    // vector<vector<int>> matrix{{2, 5, 8}, {4, 0, -1}};
    auto result = spiralOrder_consise(matrix);
    printVector<int>(result);

    getchar();

    return 0;
}