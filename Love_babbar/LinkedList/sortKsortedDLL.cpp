#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/sort-a-k-sorted-doubly-linked-list/1

// User function Template for C++


// a node of the doubly linked list
class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution {
  public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        // code here
        if(!head || head->next == nullptr) return head;
        
        priority_queue<DLLNode*, vector<DLLNode*>, 
                       function<bool(DLLNode*, DLLNode*)>> pq(
            [](DLLNode* a, DLLNode* b) { return a->data > b->data; });
            
         DLLNode * newHead = nullptr;
          DLLNode * last = nullptr;
        
         DLLNode * curr = head;
        for(int i=0 ;curr && i<= k; i++){
            pq.push(curr);
            curr = curr->next;
        }
        
        while(!pq.empty()){
             DLLNode * temp = pq.top();
             pq.pop();
             
             //if its first node new list i.e head
             if(!newHead){
                 newHead = temp;
                 newHead->next = nullptr;
                 last = temp;
             }else{
                 last->next = temp;
                 temp->prev = last;
                 last = temp;
             }
             
             if(curr){
                 pq.push(curr);
                 curr = curr->next;
             }
             
             
        }
        
        last->next = nullptr;
        return newHead;
    }
};