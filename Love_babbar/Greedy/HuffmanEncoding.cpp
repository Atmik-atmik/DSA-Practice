#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/problems/huffman-encoding3345/1

// still to do if two nodes values are equal

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class cmp{
public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

void Traverse(Node* root, string temp, vector<string>& ans){

    if(root == NULL) return;

    // Leaf node
    if(root->left == NULL && root->right == NULL){
        ans.push_back(temp);
        return;
    }

    // Go left → add 0
    Traverse(root->left, temp + '0', ans);

    // Go right → add 1
    Traverse(root->right, temp + '1', ans);
}

class Solution {
public:
    vector<string> huffmanCodes(string &s, vector<int> f) {

        priority_queue<Node*, vector<Node*>, cmp> pq;

        // Put all frequencies into min heap
        for(int i = 0; i < f.size(); i++){
            Node* temp = new Node(f[i]);
            pq.push(temp);
        }

        // Build Huffman Tree
        while(pq.size() > 1){

            Node* left = pq.top();
            pq.pop();

            Node* right = pq.top();
            pq.pop();

            int NewData = left->data + right->data;

            Node* temp = new Node(NewData);

            // Connect children
            temp->left = left;
            temp->right = right;

            pq.push(temp);
        }

        Node* root = pq.top();

        vector<string> ans;
        Traverse(root, "", ans);

        return ans;
    }
};