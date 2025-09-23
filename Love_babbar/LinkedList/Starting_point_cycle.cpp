#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

    //in cycle distance is calculate as modulo of total distand
    //i.e kC%C , where c= lengh of loop and k is number of cycle or total distance coverd in cycle;
    // so since A= kC -B , here kC -B distance is inside circle so total distatnce will be (kC -B)%C , so A = kC%C - B%C => A= B%C or C- B;
    
class Solution {
public:
    // Detects intersection point of slow and fast if cycle exists
    ListNode* Intersection(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow) {
                return slow;
            }
        }
        return nullptr;
    }

    // Returns start of cycle if present, otherwise nullptr
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;

        ListNode* intersection = Intersection(head);
        if(intersection == nullptr) return nullptr;

        ListNode* slow = head;
        while(slow != intersection) {
            slow = slow->next;
            intersection = intersection->next;
        }
        return slow;
    }
};
