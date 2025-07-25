/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool validate(TreeNode* node,long minVal,long maxVal)
    {
        if (!node) return true;
        if (node->val<=minVal || node->val>=maxVal)
            return false;
        return validate(node->left,minVal,node->val) && validate(node->right,node->val,maxVal); //since for node->left, value should be a maximum of value of node, not greater than that, and similarly, value of node->right should be at least node
    }

    bool isValidBST(TreeNode* root) {
        
        return validate(root,LONG_MIN,LONG_MAX);
    }
};