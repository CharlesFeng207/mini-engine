#include <iostream>
#include <time.h>
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

void quickSort(vector<int> &a, int startIndex, int endIndex)
{
    if (endIndex <= startIndex)
        return;

    int pivot = a[startIndex];
    int i = startIndex;
    int j = endIndex + 1;

    while (true)
    {
        while (pivot > a[++i] && i < endIndex)
        {
        }

        while (pivot < a[--j] && j > startIndex)
        {
        }

        if (i >= j)
            break;

        swap(a[i], a[j]);
    }

    swap(a[startIndex], a[j]);

    quickSort(a, startIndex, j - 1);
    quickSort(a, j + 1, endIndex);
}

void quickSort(vector<int> &a)
{
    quickSort(a, 0, a.size() - 1);
}

void test(vector<int> &a)
{
    int start = clock();
    quickSort(a, 0, a.size() - 1);
    cout << clock() - start << endl;
}

int main()
{
    vector<int> v;
    for (int i = 5; i >= 0; i--)
        v.push_back(i);

    vector<int> v2;
    for (int i = 100; i >= 0; i--)
        v2.push_back(rand());

    // vector<int> v3{3, 4, 1, 2, 5, 0};

    // test(v3);
    test(v2);

    // cout << v[0] << endl;
    printVector<int>(v2);
    getchar();
}