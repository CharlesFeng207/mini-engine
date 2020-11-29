#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <type_traits>
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
void inner_combinations(T &v, int currentIndex, int currentDepth, int endingDepth, T &temp, vector<T> &result)
{
    if (currentDepth > endingDepth)
    {
        result.emplace_back(temp);
    }
    else
    {
        auto endingIndex = v.size() - temp.size() + currentDepth;
        for (auto i = currentIndex; i <= endingIndex; i++)
        {
            temp[currentDepth] = v[i];

            inner_combinations(v, i + 1, currentDepth + 1, endingDepth, temp, result);
        }
    }
}

template <typename T>
vector<T> combinations(T &v, int count)
{
    auto size = v.size();
    if (count > size)
        return {};

    vector<T> result;

    T t(count);
    inner_combinations(v, 0, 0, count - 1, t, result);

    return result;
}

template <typename T>
vector<T> combinations(string &v, int count)
{
    if (count > v.size())
        return {};

    vector<T> result;

    string t("", count);
    inner_combinations(v, 0, 0, count - 1, t, result);

    return result;
}

int main()
{
    cout << "loop combination examples" << endl;
    vector<int> A{1, 2, 3, 4, 5};
    for (int i = 0; i < A.size() - 2; ++i)
        for (int j = i + 1; j < A.size() - 1; ++j)
            for (int k = j + 1; k < A.size(); ++k)
            {
                cout << A[i] << A[j] << A[k] << endl;
            }

    cout << "test_combination vector<int>" << endl;

    auto v = new vector<int>{1, 2, 3, 4, 5};

    auto result = combinations<vector<int>>(*v, 3);
    for (auto &t : result)
        printVector<int>(t);

    cout << "count: " << result.size() << endl;

    cout << "test_combination string" << endl;

    string str = "ABCDE";
    auto result2 = combinations<string>(str, 3);
    for (auto &t : result2)
        cout << t << endl;
    cout << "count: " << result.size() << endl;

    delete v;
    getchar();
}