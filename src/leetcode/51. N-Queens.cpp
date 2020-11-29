// https://leetcode.com/problems/n-queens/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node
{
    int x, y;
    Node *parent = NULL;

    Node(int x, int y, Node *parent) : x(x), y(y), parent(parent)
    {
    }
};

bool checkPos(Node *n, int x, int y)
{
    auto t = n;

    while (t != NULL)
    {
        if (x == t->x || y == t->y)
            return false;

        if (abs(x - t->x) == abs(y - t->y))
            return false;

        t = t->parent;
    }

    return true;
}

vector<Node *> nQueens(int n)
{
    vector<Node *> result;
    stack<Node *> open;

    for (int i = 0; i < n; i++)
    {
        open.emplace(new Node(i, 0, (Node *)NULL));
    }

    while (!open.empty())
    {
        auto t = open.top();
        open.pop();

        if (t->y == n - 1)
        {
            result.push_back(t);
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            if (checkPos(t, i, t->y + 1))
            {
                open.emplace(new Node(i, t->y + 1, t));
            }
        }
    }

    return result;
}

void printSolution(int n, Node *solution)
{
    vector<vector<int>> a(n, vector<int>(n, 0));

    auto t = solution;

    while (t != NULL)
    {
        a[t->y][t->x] = 1;
        t = t->parent;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}


vector<vector<string>> solveNQueens(int n)
{
    auto solutions = nQueens(n);

    vector<vector<string>> results;

    for (auto &node : solutions)
    {
        vector<string> vect_str(n, string(n, '.'));

        auto t = node;

        while (t != NULL)
        {
            vect_str[t->y][t->x] = 'Q';
            t = t->parent;
        }

        results.push_back(vect_str);
    }

    // NodeFactory::clear();

    return results;
}

int main()
{
    auto results = solveNQueens(4);

    for (auto &v : results)
    {
        for (auto &s : v)
        {
            cout << s << endl;
        }
        cout << endl;
    }

    getchar();
    return 0;
}