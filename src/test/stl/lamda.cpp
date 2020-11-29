#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(int a, int b)
{
    return a < b;
}

void TestCallback(function<int(int, int)> func)
{
    cout << "callback " << func(1, 2) << endl;
}

int main()
{
    vector<int> myvec{3, 2, 5, 7, 3, 2};

    vector<int> lbvec(myvec);

    sort(myvec.begin(), myvec.end(), cmp); // 旧式做法
    cout << "predicate function:" << endl;

    for (int it : myvec)
        cout << it << ' ' << endl;

    int t = 0;

    function<int(int, int)> func = [&t](int a, int b) -> bool { 
        t ++;
        return a < b; };

    sort(lbvec.begin(), lbvec.end(), func); // Lambda表达式

    cout << "lambda expression:" << endl;
    for (int it : lbvec)
        cout << it << ' ' << endl;

    cout << "t:" << t << endl;

    cout << "lamda call " << func(1, 2) << endl;
    TestCallback(func);

    getchar();
}