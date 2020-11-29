// #include <float.h>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    float ff = 1.2;
    int a = 1;

    while (true)
    {
        static int i = 0;
        system("cls");
        cout << string("Hello") + "World!" << a << " " << ff << endl;
        cout << i++ << endl;
        Sleep(100);
    }

    getchar();
}