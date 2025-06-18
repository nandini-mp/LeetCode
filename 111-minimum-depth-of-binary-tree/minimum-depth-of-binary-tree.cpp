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
    int minDepth(TreeNode* root) {
        if (!root) return 0; //current node is null, meaning we're at the end of a path - this contributes no depth so return 0
        int leftDepth=minDepth(root->left); //get min depth of left subtree recursive
        int rightDepth=minDepth(root->right); //similarly right
        if (!root->left || !root->right) //if either left or right child is missing, we ignore the missing child and take the depth from the non-null side
            return max(leftDepth,rightDepth)+1;
        return min(leftDepth,rightDepth)+1; //if both children exist, we can choose the shorter path to a leaf
    }
};