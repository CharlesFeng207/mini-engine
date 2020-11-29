#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void shuffle(int *a, int n)
{
    if (n <= 0)
        return;

    for (int i = 0; i < n; i++)
    {
        int j = i + rand() % (n - i);
        swap(a[i], a[j]);
    }
}

int main()
{
    int len = 7;
    int a[] = {1, 2, 3, 4, 5, 6, 7};

    shuffle(a, len);

    for (int i = 0; i < len; i++)
    {
        cout << a[i] << endl;
    }

    getchar();
}