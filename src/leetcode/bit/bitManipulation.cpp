// https://www.learncpp.com/cpp-tutorial/3-8a-bit-flags-and-bit-masks/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Define 8 separate bit flags (these can represent whatever you want)
const unsigned char option0 = 1 << 0; // 0000 0001
const unsigned char option1 = 1 << 1; // 0000 0010
const unsigned char option2 = 1 << 2; // 0000 0100
const unsigned char option3 = 1 << 3; // 0000 1000
const unsigned char option4 = 1 << 4; // 0001 0000
const unsigned char option5 = 1 << 5; // 0010 0000
const unsigned char option6 = 1 << 6; // 0100 0000
const unsigned char option7 = 1 << 7; // 1000 0000

unsigned char myflags = 0; // all bits turned off to start

int isPower(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}

int main()
{
    /*
    myflags = 0000 0000 (we initialized this to 0)
    option4 = 0001 0000
    -------------------
    result  = 0001 0000
     */
    myflags |= option4; // turn option 4 on
    /*
    myflags  = 0001 1100
    ~option4 = 1110 1111
    --------------------
    result   = 0000 1100
    */
    myflags &= ~option4; // turn option 4 off

    myflags &= ~(option4 | option5); // turn options 4 and 5 off at the same time

    /*
    myflags = 0001 1100
    option4 = 0001 0000
    --------------------
    result  = 0000 1100
    */
    myflags ^= option4;             // flip option4 from on to off, or vice versa
    myflags ^= (option4 | option5); // flip options 4 and 5 at the same time

    if (myflags & option4)
        std::cout << "myflags has option 4 set" << endl;

    if (myflags & option5)
        std::cout << "myflags has option 5 set" << endl;

    // swap two numbers

    // 0 0 1
    int a = 1;
    // 0 1 0
    int b = 2;

    // a = 0 1 1
    a = a ^ b;
    // b = 0 0 1
    b = a ^ b;
    // a = 0 1 0
    a = a ^ b;

    cout << "a " << a << " b " << b << endl;

    cout << "isPower: 100 ->" << isPower(100) << endl;

    cout << "isPower: 200 -> " << isPower(200) << endl;

    cout << "isPower: 128 -> " << isPower(128) << endl;

    cout << "isPower: 2 -> " << isPower(2) << endl;

    cout << ((2 > 0) && ((2 & 1) == 0)) << endl;

    getchar();

    return 0;
}