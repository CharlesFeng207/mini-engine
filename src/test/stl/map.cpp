#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


int main()
{
    //http://c.biancheng.net/stl/map/
    // map<int, string> m;
    unordered_map<int, string> m;
    m.insert(pair<int, string>(1, "123"));

    //当map中有这个关键字时，insert操作是插入数据不了的
    m.insert(pair<int, string>(1, "321"));

    // 数组的方式理论上可以，但win的clang环境下不行
    cout << "m[1] m[2]" << endl;
    cout << m[1] << endl;
    m[1] = "321";
    cout << m[1] << endl;
    m[2] = "3212";
    cout << m[2] << endl;
    cout << "m[3]:" << m[3] << endl;
    cout << endl;

    cout << "iter" << endl;
    auto iter = m.begin();
    
    while (iter != m.end())
    {
        cout << iter->first << ':' << iter->second << endl;
        iter++;
    }
    cout << endl;

    string str = "lamda";
    for_each(m.begin(), m.end(), [&str](auto &a) {
        cout << str << endl;
        cout << a.first << ":" << a.second << endl;
    });

    iter = m.find(1);
    if (iter != m.end())
    {
        iter->second += "add";
        cout << iter->second << endl;
    }

    vector<int> v{1, 2, 3, 4, 5};
    unordered_map<int, int> m2();


    getchar();

    return 0;
}