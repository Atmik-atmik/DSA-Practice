#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Solution {
public:
    // Step 1: Detect intersection point inside the cycle (if it exists)
    Node* getIntersection(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                return slow; // intersection point
            }
        }
        return nullptr;
    }

    // Step 2: Detect cycle start node
    Node* detectCycle(Node* head) {
        if(head == nullptr) return nullptr;

        Node* intersection = getIntersection(head);
        if(intersection == nullptr) return nullptr; // no cycle

        Node* slow = head;
        while(slow != intersection) {
            slow = slow->next;
            intersection = intersection->next;
        }
        return slow; // start of the cycle
    }

    // Step 3: Remove cycle if present
    void removeLoop(Node* head) {
        if(head == nullptr) return;

        Node* start = detectCycle(head);
        if(start == nullptr) return; // no loop, nothing to remove

        Node* temp = start;
        while(temp->next != start) {
            temp = temp->next;
        }
        temp->next = nullptr; // break the cycle
    }
};
