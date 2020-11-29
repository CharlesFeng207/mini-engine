#include <iostream>
#include <vector>

using namespace std;

int inner_binearySearch(vector<int> &a, int t, int startIndx, int endIndex)
{
    int pivotIndex = (startIndx + endIndex) / 2;
    int pivotValue = a[pivotIndex];

    if (t == pivotValue)
    {
        return pivotIndex;
    }
    else if (startIndx == endIndex)
    {
        return -1;
    }

    if (t > pivotValue)
    {
        return inner_binearySearch(a, t, pivotIndex + 1, endIndex);
    }
    else
    {
        return inner_binearySearch(a, t, startIndx, pivotIndex - 1);
    }
}

int bineaySearch(vector<int> &a, int t)
{
    return inner_binearySearch(a, t, 0, a.size() - 1);
}

int binarySearch_no_recursive(vector<int> &a, int t)
{
    int start = 0;
    int end = a.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (a[mid] == t)
            return mid;
        else if (mid > t)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int main()
{
    vector<int> v;
    for (int i = 0; i < 100000; i++)
        v.push_back(i);

    cout << bineaySearch(v, 9991) << endl;
    cout << bineaySearch_no_recursive(v, 9991) << endl;
    cout << endl;
    cout << bineaySearch(v, 100001) << endl;
    cout << bineaySearch_no_recursive(v, 100001) << endl;

    getchar();
}
