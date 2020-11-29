// #include <float.h>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    char str[][10] = {"Hello", "World2299"};
    char *p = str[0];
    cout << strlen(p + 10) << endl; //p是字符指针,+1位移一个 sizeof(char) 二维数组第二维长度是10，那么p+10就指向了字符w

    cout << sizeof(char) << endl; // 返回一个对象或者类型所占的内存字节数
    cout << sizeof(char[10]) << endl;

    cout << sizeof(p) << endl;

    getchar();
}