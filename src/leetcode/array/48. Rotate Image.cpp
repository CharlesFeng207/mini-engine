// https://leetcode.com/problems/rotate-image/

#include <algorithm>
#include <iostream>
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

void circle_swap(int i, int j, vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int start_i = i;
    int start_j = j;

    int temp_i = i;
    int temp_j = j;

    int temp_value = matrix[temp_i][temp_j];
    do
    {
        int next_i = temp_j;
        int next_j = n - 1 - temp_i;

        swap(temp_value, matrix[next_i][next_j]);

        temp_j = next_j;
        temp_i = next_i;

    } while (!(temp_i == start_i && temp_j == start_j));
}

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i <= n / 2; i++)
    {
        for (int j = i; j < n - 1 - i; j++)
        {
            circle_swap(i, j, matrix);
        }
    }
}

void rotate_simple(vector<vector<int>> &m)
{
    int n = m.size();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            swap(m[i][j], m[j][i]);

    for (int i = 0; i < n; i++)
        reverse(m[i].begin(), m[i].end());
}

int main()
{

    vector<vector<int>> a;
    // a.push_back({1, 2, 3});
    // a.push_back({4, 5, 6});
    // a.push_back({7, 8, 9});
    a.push_back({1, 2, 3, 4});
    a.push_back({5, 6, 7, 8});
    a.push_back({9, 10, 11, 12});
    a.push_back({13, 14, 15, 16});

    // rotate(a);
    rotate_simple(a);

    for (auto &v : a)
        printVector<int>(v);

    getchar();
    return 0;
}