// https://leetcode.com/problems/word-search/

#include <algorithm>
#include <iostream>
#include <time.h>
#include <unordered_map>
#include <vector>

using namespace std;

bool inner_exist(vector<vector<char>> &board, string &word, int index, int posX, int posY)
{
    if (posX < 0 || posX >= board[0].size() ||
        posY < 0 || posY >= board.size() ||
        board[posY][posX] != word[index])
        return false;

    if (index == word.size() - 1)
        return true;

    auto t = board[posY][posX];
    board[posY][posX] = '\0';

    if (inner_exist(board, word, index + 1, posX - 1, posY))
        return true;
    if (inner_exist(board, word, index + 1, posX + 1, posY))
        return true;
    if (inner_exist(board, word, index + 1, posX, posY - 1))
        return true;
    if (inner_exist(board, word, index + 1, posX, posY + 1))
        return true;

    board[posY][posX] = t;

    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    if (word.size() == 0)
        return false;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (inner_exist(board, word, 0, j, i))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    vector<vector<char>> board =
        {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}};

    cout << exist(board, "CSEEDF");

    getchar();
    return 0;
}