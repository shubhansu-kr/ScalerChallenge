// https://practice.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


class Solution
{
public:
    Node *deleteNode(Node *head_ref, int x)
    {
        if (!head_ref) return head_ref;
        Node *p = head_ref, *prev = nullptr;
        while(--x){
            prev = p;
            p = p->next;
        }
        if (!prev){
            head_ref = head_ref->next;
            if (head_ref) head_ref->prev = nullptr;
        }
        else {
            prev->next = p->next;
            if (p->next) p->next->prev = prev;
        }
        delete(p);
        return head_ref;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}