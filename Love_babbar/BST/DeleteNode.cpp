#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/delete-node-in-a-bst/


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    // helper function to find the minimum value node in a subtree
    TreeNode* findMin(TreeNode* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } 
        else {
            // found the node to delete
            // Case 1: no child
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // Case 2: one child (right)
            else if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // Case 2: one child (left)
            else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: two children
            TreeNode* minNode = findMin(root->right); // inorder successor
            root->val = minNode->val;
            root->right = deleteNode(root->right, minNode->val);
        }
        return root;
    }
};
