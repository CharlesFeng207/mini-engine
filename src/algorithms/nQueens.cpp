#include <algorithm>
#include <iostream>
#include <math.h>
#include <stack>
#include <time.h>
#include <vector>
#include <windows.h>

using namespace std;

struct Node
{
    int x, y;
    Node *parent = NULL;

    Node(int x, int y, Node *parent) : x(x), y(y), parent(parent)
    {
    }
};

class NodeFactory
{
public:
    static int count;
    static vector<Node *> all;
    static Node *create(int x, int y, Node *parent)
    {
        auto t = new Node(x, y, parent);
        all.push_back(t);
        count++;
        return t;
    }

    static void clear()
    {
        for (auto &n : all)
        {
            delete n;
        }
        count = 0;
        all.clear();
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
        open.emplace(NodeFactory::create(i, 0, (Node *)NULL));
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
                open.emplace(NodeFactory::create(i, t->y + 1, t));
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

vector<Node *> NodeFactory::all;
int NodeFactory::count;

int main()
{
    int n = 4;
    auto t = clock();
    auto result = nQueens(n);
    cout << "size: " << result.size() << " time: " << clock() - t << endl;
    for (auto &v : result)
    {
        cout << endl;
        printSolution(n, v);
    }

    NodeFactory::clear();

    Sleep(100);

    getchar();
}