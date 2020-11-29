#include <deque>
#include <functional>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct Node
{
    int x, y;
    Node *parent = NULL;

    Node(int x, int y, Node *parent) : x(x), y(y), parent(parent)
    {
        cout << "Node created " << x << endl;
    }

    // Overload default copy constructor, take reponsiblity for copying data.
    // (default has a copy constructor)
    Node(const Node &node)
    {
        x = node.x;
        y = node.y;
        parent = node.parent;

        cout << "Node copied " << x << endl;
    }

    ~Node()
    {
        cout << "Node destroyed " << x << endl;
    }
};

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

template <class T, class Y>
vector<Y> select(vector<T> &v, function<Y(T &)> func)
{
    vector<Y> t;
    for (auto &i : v)
    {
        t.emplace_back(func(i));
    }

    return t;
}

template <typename T>
vector<T> where(vector<T> &v, function<bool(T &)> func)
{
    vector<T> t;
    for (auto &i : v)
    {
        if (func(i))
        {
            t.emplace_back(i);
        }
    }

    return t;
}

int main()
{
    cout << "test loop add node" << endl;
    // vector<Node> v9(5, Node(-1, -1, (Node *)NULL));
    vector<Node> v9;
    for (int i = 0; i < 5; i++)
    {
        v9.emplace_back(i, i, (Node *)NULL); // Build object in container, more efficient than push_back
        // v9.push_back(Node(i, i, (Node *)NULL)); // Cause one more constrcutor and copy calling.
    }

    for (auto &v : v9)
    {
        cout << v.x << " ";
    }
    cout << endl;

    cout << "push_back" << endl;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    // v1.erase(0);
    printVector<int>(v1);

    vector<float> v2{9.9, 10.0};
    v2.push_back(1.2);
    v2.push_back(2.5);
    printVector<float>(v2);

    cout << "push_back other vector" << endl;
    vector<vector<int>> v3{{2}, {3}};
    v3.push_back(v1);
    v3.push_back(v1);
    v3.pop_back();
    for (auto &v : v3)
        printVector<int>(v);

    cout << "deque" << endl;
    deque<int> q;
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    cout << q.front() << endl;
    cout << q.front() << endl;
    q.pop_front();
    cout << q.front() << endl;

    cout << "stack" << endl;
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    cout << s.top() << endl;

    cout << "assign(v1.begin(), v1.end());" << endl;
    vector<int> v4;
    v4.assign(v1.begin(), v1.begin() + 2);
    vector<int> v5(v1.begin(), v1.end() - 1);
    printVector(v4);
    printVector(v5);

    cout << "vector<vector<int>>(10)" << endl;
    vector<int> v6(10, 6);
    printVector(v6);

    cout << "linq where" << endl;
    auto v7 = where<int>(v1, [](int &i) { return i > 3; });
    printVector(v7);

    cout << "linq select" << endl;
    auto v8 = select<int, string>(v7, [](int &i) { return to_string(i) + "x"; });
    printVector(v8);

    // ==989==ERROR: AddressSanitizer: heap-buffer-overflow
    // cout << v8[-1] << endl;
    // cout << v8[2] << endl;

    getchar();

    return 0;
}
