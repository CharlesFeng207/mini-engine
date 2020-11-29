#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
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

template <typename T>
void inner_permutations(T &v, int currentDepth, int endingDepth, vector<T> &result)
{
    if (currentDepth == endingDepth)
        result.emplace_back(v);
    else
    {
        for (auto i = currentDepth; i <= endingDepth; i++)
        {
            swap(v[currentDepth], v[i]);

            inner_permutations(v, currentDepth + 1, endingDepth, result);

            swap(v[currentDepth], v[i]); //backtrack
        }
    }
}

template <typename T>
vector<T> permutations(T &v)
{
    vector<T> result;
    if (v.size() < 2)
    {
        if (v.size() == 1)
        {
            result.push_back(v);
        }
        return result;
    }

    auto endingDepth = v.size() - 1;
    inner_permutations(v, 0, endingDepth, result);
    return result;
}

int main()
{
    cout << "next_permutation (must perform in a sorted vector)" << endl;

    auto vv = new vector<int>{1, 2};
    auto v = new vector<int>(*vv);

    do
    {
        printVector<int>(*v);
    } while (next_permutation(v->begin(), v->end()));

    cout << "recursive permutation vector<int>" << endl;

    auto v2 = vector<int>(*vv);

    auto result =
        permutations<vector<int>>(v2);

    for (auto &t : result)
        printVector<int>(t);

    cout << "recursive permutation string" << endl;

    char ca[] = "ABC";
    string str = ca;

    auto result2 = permutations<string>(str);
    for (auto &t : result2)
        cout << t << endl;

    delete v;
    delete vv;

    getchar();
}