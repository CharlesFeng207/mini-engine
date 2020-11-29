// https://leetcode.com/problems/add-two-numbers/

#include <algorithm>
#include <iostream>
#include <time.h>
#include <unordered_map>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *createListNode(int num)
{
    auto str = to_string(num);
    vector<ListNode *> a(str.size(), NULL);

    for (int i = 0; i < str.size(); i++)
    {
        // Char to int, number start from 48 in ascii. = stoi(string(1, str[i]));
        int iv = str[i] - 48;

        a[i] = new ListNode(iv);

        if (i != 0)
        {
            a[i]->next = a[i - 1];
        }
    }

    return a[a.size() - 1];
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    auto t1 = l1;
    auto t2 = l2;

    int carry = 0;
    ListNode *result = NULL;
    ListNode *pre = NULL;

    while (t1 != NULL || t2 != NULL || carry != 0)
    {
        int tv1 = t1 == NULL ? 0 : t1->val;
        int tv2 = t2 == NULL ? 0 : t2->val;

        int t = carry + tv1 + tv2;
        carry = t >= 10;
        int tv3 = t % 10;

        auto node = new ListNode(tv3);
        if (result == NULL)
            result = node;

        if (pre != NULL)
        {
            pre->next = node;
        }

        pre = node;

        if (t1 != NULL)
            t1 = t1->next;

        if (t2 != NULL)
            t2 = t2->next;
    }

    return result;
}

int main()
{
    auto l1 = createListNode(5);
    auto l2 = createListNode(5);

    auto result = addTwoNumbers(l1, l2);

    auto t = result;
    while (t != NULL)
    {
        cout << t->val << " ";
        t = t->next;
    }

    getchar();
    return 0;
}