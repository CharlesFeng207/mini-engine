#include <iostream>
#include <string>
#include <vector>

using namespace std;

string join(vector<string> &v, string c)
{
    string s;

    for (auto p = v.begin();
         p != v.end(); ++p)
    {
        s += *p;
        if (p != v.end() - 1)
            s += c;
    }

    return s;
}

int main()
{
    cout << "size and sizeof" << endl;
    auto *ps = new string("Memory Management");
    cout << "size(): " << ps->size() << endl;
    cout << "sizeof(): " << sizeof(*ps) << endl;

    delete ps;

    cout << "after delete" << endl;
    cout << "size(): " << ps->size() << endl;
    cout << "sizeof(): " << sizeof(*ps) << endl
         << endl;

    string s = "123";

    for (int i = 0; i < s.length(); i++)
        cout << s[i] << endl;

    cout << "size and length" << endl;

    cout << s.size() << endl;
    cout << s.length() << endl
         << endl;

    cout << "find 32 from string" << endl;

    if (s.find("32") == string::npos)
        cout << "not found" << endl
             << endl;

    cout << "string to int" << endl;
    int t = stoi(s);
    cout << t + 1 << endl;

    cout << "int to string" << endl;
    cout << to_string(t) + "ABC" << endl
         << endl;

    cout << "string join" << endl;
    vector<string> v{"Hello, ", " Cruel ", "World!"};

    string st;
    for (auto &piece : v)
        st += piece;

    cout << st << endl;

    cout << join(v, "^") << endl;

    getchar();

    return 0;
}