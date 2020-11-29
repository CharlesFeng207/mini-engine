#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

vector<int> KMP_pre_DP(string &t)
{
    vector<int> dp(t.size(), 0);

    // n从1开始加规模，其实就是看新的字符能不能和以上一次的数值做索引的字符匹配得上不
    for (int i = 1; i < t.size(); i++)
    {
        int pre = dp[i - 1];
        if (t[i] == t[pre])
        {
            dp[i] = pre + 1;
        }
        else
        {
            dp[i] = 0;
        }
    }

    return dp;
}

// Algorithm complexity O(n)
bool KMP(string &s, string &t)
{
    auto f = KMP_pre_DP(t);

    int size = s.size() - t.size();

    for (int i = 0; i < size;)
    {
        for (int j = 0; j < t.size(); j++)
        {
            if (s[i + j] != t[j])
            {
                // 移动位数 = 已匹配的字符数 - 对应的部分匹配值
                int step = j == 0 ? 1 : j - f[j - 1];
                i += step;
                break;
            }

            if (j == t.size() - 1)
                return true;
        }
    }

    return false;
}

// Algorithm complexity O(n*m)
bool bruteforce(string &s, string &t)
{
    int size = s.size() - t.size();

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < t.size(); j++)
        {
            if (s[i + j] != t[j])
            {
                break;
            }

            if (j == t.size() - 1)
            {
                return true;
            }
        }
    }

    return false;
}

void test_case(string s, int n, string target)
{
    cout << "test_case ------------- " << s << " x" << n << endl;

    string str;
    for (int i = 0; i < n; i++)
    {
        str += s;
    }

    int t = clock();
    auto iter = str.find(target);
    if (iter == string::npos)
    {
        cout << "STL not found" << endl;
    }
    else
    {

        cout << "STL found" << endl;
    }

    cout << "STL: " << clock() - t << " ms" << endl;

    t = clock();
    if (!bruteforce(str, target))
    {
        cout << "bruteforce not found" << endl;
    }
    else
    {
        cout << "bruteforce found" << endl;
    }

    cout << "bruteforce: " << clock() - t << " ms" << endl;

    t = clock();
    if (!KMP(str, target))
    {
        cout << "KMP not found" << endl;
    }
    else
    {
        cout << "KMP found" << endl;
    }

    cout << "KMP: " << clock() - t << " ms" << endl;

    cout << "end" << endl;
}

// string s("ABCDABD");
// string s("abcabcab");
string s("abcabcabc");

void test_kmp_pre()
{
    cout << endl
         << "KMP_pre_DP" << endl;

    auto v = KMP_pre_DP(s);

    for (auto &i : v)
        cout << i << " ";

    cout << endl;
}

int main()
{
    test_kmp_pre();

    test_case("abcddfkjgmnabcsmgksabcabc", 1000000, s);
    // test_case("abcddfkjgmnsmgksdmf", 10000000, "abcddfkjgmnsmgksdmfa");
    getchar();

    return 0;
}