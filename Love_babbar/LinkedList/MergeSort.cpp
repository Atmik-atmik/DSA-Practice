#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/sort-a-linked-list/1

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class Solution
{
public:
    Node *merge(Node *left, Node *right)
    {

        // If one list is empty
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;

        Node *ans = new Node(-1);
        Node *temp = ans;

        // Compare both lists until one becomes empty
        while (left != NULL && right != NULL)
        {

            if (left->data < right->data)
            {
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else
            {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        // Attach remaining nodes
        if (left == NULL)
        {
            temp->next = right;
        }

        if (right == NULL)
        {
            temp->next = left;
        }

        return ans->next;
    }

    Node *findMid(Node *head)
    {

        Node *slow = head;
        Node *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    Node *mergeSort(Node *head)
    {

        // Base case
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // Find middle
        Node *mid = findMid(head);

        // Break into two lists
        Node *left = head;
        Node *right = mid->next;

        mid->next = NULL;

        // Sort both halves
        left = mergeSort(left);
        right = mergeSort(right);

        // Merge sorted halves
        Node *result = merge(left, right);

        return result;
    }
};