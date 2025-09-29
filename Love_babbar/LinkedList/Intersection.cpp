#include <bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL|| headB == NULL) return headA;

        ListNode* a = headA;
        ListNode* b = headB;

        while(a != b){
            a = (a == NULL )? a= headB: a= a->next;
            b = (b== NULL )? b= headA: b= b->next;
        }

        return a;
    }
};