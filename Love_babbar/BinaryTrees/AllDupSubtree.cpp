#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-duplicate-subtrees/


  
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
    string getSubTreeString(TreeNode* node,unordered_map<string, int>&mp, 
    vector<TreeNode*>&result){
        if(node == nullptr) return "N";

        string s = to_string(node->val) + "," + getSubTreeString(node->left,mp,result) + "," +  getSubTreeString(node->right,mp,result) ;
       

        if(mp[s] == 1) result.push_back(node);

        mp[s] ++;

        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int>mp;
        vector<TreeNode*> result;
        getSubTreeString(root,mp,result);
        return result;
    }
};