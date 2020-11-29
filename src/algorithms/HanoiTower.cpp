#include <iostream>
#include <vector>

using namespace std;

void hannoi(int n, char from, char t, char to)
{
    if (n == 1)
    {
        cout << "n:" << n << " from " << from << " to " << to << endl;
    }
    else
    {
        hannoi(n - 1, from, to, t);
        cout << "n:" << n << " from " << from << " to " << to << endl;
        hannoi(n - 1, t, from, to);
    }
}

int main()
{
    hannoi(3, '1', '2', '3');
    getchar();
}