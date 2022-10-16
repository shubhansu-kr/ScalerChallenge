// https://leetcode.com/problems/insertion-sort-list/

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
    ListNode* insertionSortList(ListNode* head) {
        // Add a infinity element before head. 
        ListNode *p = new ListNode(INT_MIN);
        p->next = head;
        head = p;

        p = head->next;
        ListNode *q, *prevP = head, *prevQ;
        while(p){
            q = head->next;
            prevQ = head;
            int flag = 1;
            while(q != p && q) {
                if (q->val < p->val){
                    prevQ = q;
                    q = q->next;
                }
                else {
                    prevP->next = p->next;
                    // now p is hanging. 
                    p->next = q;
                    prevQ->next = p;
                    flag = 0;
                    break; 
                }
            }
            if (flag) {
                prevP = p;
                p = p->next;
            }
            else {p = prevP->next;}
        }
        return head->next;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}