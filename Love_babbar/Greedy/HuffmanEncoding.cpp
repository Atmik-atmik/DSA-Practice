#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/problems/huffman-encoding3345/1


class Node {
public:
    int data;
    int index;
    Node* left;
    Node* right;

    Node(int d, int i) {
        data = d;
        index = i;
        left = NULL;
        right = NULL;
    }
};

class cmp {
public:
    bool operator()(Node* a, Node* b) {

        // Same frequency
        if (a->data == b->data) {
            return a->index > b->index;
        }

        // Smaller frequency gets higher priority
        return a->data > b->data;
    }
};

void Traverse(Node* root, string temp, vector<string>& ans) {

    if (root == NULL)
        return;

    // Leaf node
    if (root->left == NULL && root->right == NULL) {
        ans.push_back(temp);
        return;
    }

    // Left -> 0
    Traverse(root->left, temp + '0', ans);

    // Right -> 1
    Traverse(root->right, temp + '1', ans);
}

class Solution {
public:

    vector<string> huffmanCodes(string &s, vector<int> f) {

        priority_queue<Node*, vector<Node*>, cmp> pq;

        // Create leaf nodes
        for (int i = 0; i < f.size(); i++) {
            Node* temp = new Node(f[i], i);
            pq.push(temp);
        }

        // Single character case
        if (pq.size() == 1) {
            return {"0"};
        }

        // Build Huffman Tree
        while (pq.size() > 1) {

            Node* left = pq.top();
            pq.pop();

            Node* right = pq.top();
            pq.pop();

            int NewData = left->data + right->data;

            // Earliest character in this subtree
            int NewIndex = min(left->index, right->index);

            Node* temp = new Node(NewData, NewIndex);

            // Left -> 0
            temp->left = left;

            // Right -> 1
            temp->right = right;

            pq.push(temp);
        }

        Node* root = pq.top();

        vector<string> ans;

        Traverse(root, "", ans);

        return ans;
    }
};