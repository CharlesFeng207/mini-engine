// https://leetcode.com/problems/linked-list-cycle-ii/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        /* entry point is the start point of circle
L1 is defined as the distance between the head point and entry point
L2 is defined as the distance between the entry point and the meeting point

Distance traveled by slow when they meet: L1+L2
Distance traveled by fast when they meet: L1+L2+x+L2, where x is the remaining length of the cycle (meeting point to start of the cycle).

2(L1+L2) = L1 + L2 + x + L2
2L1 + 2L2 = L1 + 2L2 + x
=> x = L1

so we need to move L1 steps from the current meeting point to reach the entry point of the cycle.
*/
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }

    return NULL;
}

int main()
{
    auto e = new ListNode(4);
    auto d = new ListNode(3);
    auto c = new ListNode(2);
    auto b = new ListNode(1);
    auto a = new ListNode(0);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = c;

    auto t = detectCycle(a);

    if (t == NULL)
    {
        cout << "no circle" << endl;
    }
    else
    {
        cout << t->val << endl;
    }

    getchar();

    return 0;
}