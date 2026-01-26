#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *curr = head;
        Node *prev = NULL;

        while (curr)
        {
            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    Node *compute(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        head = reverse(head);

        Node *curr = head;
        int maxVal = curr->data;

        while (curr->next)
        {
            if (curr->next->data < maxVal)
            {
                curr->next = curr->next->next;
            }
            else
            {
                curr = curr->next;
                maxVal = curr->data;
            }
        }

        head = reverse(head);
        return head;
    }
};
