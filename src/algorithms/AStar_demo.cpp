#include "AStar.h"
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
// #include <windows.h>

using namespace std;

void printSolution(vector<vector<int>> &maze, list<Node> path)
{
    if (path.size() == 0)
        return;

    vector<vector<int>> a = maze;

    for (auto &n : path)
    {
        a[n.y][n.x] = 2;
    }

    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

// auto AStar::testInt = 0;

int main()
{
    // system("cls");

    auto map = new vector<vector<int>>{
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1},
        {1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    // while (true)
    // {
    auto astar = new AStar(map);
    auto path = astar->search(1, 1, 6, 2);
    printSolution(*map, path);
    delete astar;
    // }

    // Sleep(100);
    getchar();
    return 0;
}
