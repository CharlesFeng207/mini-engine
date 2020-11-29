// #include <float.h>
#include <assert.h>
#include <cstring>
#include <iostream>

using namespace std;

char *strcopytest(char *des, const char *src)
{
    assert(des != NULL && src != NULL);

    char *r = des;
    while ((*des++ = *src++) != '\0')
        ;
    return r;
}

int strcmptest(const char *s1, const char *s2)
{
    assert(s1 != NULL && s2 != NULL);

    while (*s1++ == *s2++)
    {
        if (*s1 == '/0')
            break;
    }

    return *s1 == *s2 ? 1 : 0;
}

int main()
{
    // char s2[] = "asdp32132";

    // cout << strcmptest("asdp32132", "3123123") << endl;
    char dest[] = "4321";
    char src[] = "123";
    
    // strcopytest(dest, src);

    cout << dest << endl;

    cout << strcmptest(dest, "4321") << endl;
    // cout << strcmp("asd", "asd3xzx") << endl;
    // cout << strcmp("asd2xxx", "asd2xxx") << endl;
}