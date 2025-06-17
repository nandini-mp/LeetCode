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
    int height(TreeNode* root)
    {
        if (!root) return 0;
        int maxLeft=height(root->left);
        int maxRight=height(root->right);
        return max(maxLeft,maxRight)+1;
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int heightDiff=height(root->left)-height(root->right);
        if (abs(heightDiff)>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};