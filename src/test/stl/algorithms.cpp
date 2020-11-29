#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
void printVector(vector<T> vector)
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

int main()
{
    auto v = new vector<int>{2, 2, 3, 4, 5, 6};

    cout << "swap" << endl;
    swap(*(v->begin()), *(v->end() - 1));
    printVector<int>(*v);
    cout << "iter_swap" << endl;
    iter_swap(v->begin(), v->end() - 1);
    printVector<int>(*v);

    cout << "reverse, for_each + lamda" << endl;
    reverse(v->begin(), v->end());
    int t = 0;
    for_each(v->begin(), v->end(), [&t](int &p) { cout << t++ * 2 + p << " "; });
    cout << endl;

    cout << "random_shuffle" << endl;
    random_shuffle(v->begin(), v->end());
    printVector<int>(*v);

    cout << "sort + lamda" << endl;
    sort(v->begin(), v->end(), [](int &a, int &b) { return a < b; }); // return false means need to swap a b
    printVector<int>(*v);
    random_shuffle(v->begin(), v->end());
    sort(v->begin(), v->end());
    printVector<int>(*v);

    cout << "binary_search: 4 (must perform in a sorted vector)" << endl;
    cout << binary_search(v->begin(), v->end(), 4) << endl;

    cout << "any_of > 5" << endl;
    cout << any_of(v->begin(), v->end(), [](auto &a) {
        return a > 5;
    }) << endl;

    cout << "all_of < 7" << endl;
    cout << all_of(v->begin(), v->end(), [](auto &a) {
        return a < 7;
    }) << endl;

    cout << "lower_bound (x > 0)" << endl;
    auto f = lower_bound(v->begin(), v->end(), 0);
    cout << *f << endl;

    cout << "max_element" << endl;
    auto maxValue = max_element(v->begin(), v->end());
    cout << *maxValue << endl;

    delete v;
    getchar();
}