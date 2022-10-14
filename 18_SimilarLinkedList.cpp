// https://www.hackerrank.com/challenges/compare-two-linked-lists/problem

#include <bits/stdc++.h>
using namespace std;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

class Solution
{
public:
    bool compare_lists(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
    {
        SinglyLinkedListNode *p1 = head1, *p2=head2;
        while(p1 && p2) {
            if (p1->data != p2->data) return false;
            p1 = p1->next;
            p2 = p2->next;       
        }
        return p1 == p2;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}