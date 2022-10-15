// https://leetcode.com/problems/merge-nodes-in-between-zeros/

#include <bits/stdc++.h>
using namespace std ;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *p = head, *q = head->next, *prev = nullptr;
        int sum = 0;
        while(q) {
            if (q->val){
                sum += q->val;
            }
            else {
                p->val = sum;
                sum = 0;
                p->next = q;
                prev = p;
                p = q;
            }
            q = q->next;
        }
        prev->next = nullptr;
        return head;
    }
};

class Solution {
    // WA : WE need to omit the zeroes as well 
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *p = head, *q = head->next;
        int sum = 0;
        while(q) {
            if (q->val){
                sum += q->val;
            }
            else {
                p->next->val = sum;
                sum = 0;
                p->next->next = q;
                p = q;
            }
            q = q->next;
        }
        return head;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}