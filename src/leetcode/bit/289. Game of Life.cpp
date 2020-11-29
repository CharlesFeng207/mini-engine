// https://leetcode.com/problems/game-of-life

#include <algorithm>
#include <iostream>
#include <string>
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

int coutNeighbors(vector<vector<int>> &board, int x, int y, int m, int n)
{
    int count = 0;
    for (int i = y - 1; i <= y + 1; i++)
    {
        for (int j = x - 1; j <= x + 1; j++)
        {
            if (j < 0 || j >= n || i < 0 || i >= m || (x == j && y == i))
                continue;

            count += (board[i][j] & 1);
        }
    }

    return count;
}

void gameOfLife(vector<vector<int>> &board)
{
    int m = board.size();
    if (m == 0)
        return;

    int n = board[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int lives = coutNeighbors(board, j, i, m, n);

            if ((board[i][j] & 1) && (lives == 3 || lives == 2))
            {
                board[i][j] = 3; //  01 ---> 11
            }
            else if (!(board[i][j] & 1) && lives == 3)
            {
                board[i][j] = 2; // 00 ----> 10
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] >>= 1; // Get the 2nd state.
        }
    }
}

int main()
{
    vector<vector<int>> a{{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    gameOfLife(a);

    for (auto &v : a)
        printVector<int>(v);

    getchar();
    return 0;
}