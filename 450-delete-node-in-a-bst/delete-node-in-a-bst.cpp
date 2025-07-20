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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val>key)
        {
            root->left=deleteNode(root->left,key);
            return root;
        }
        else if (root->val<key)
        {
            root->right=deleteNode(root->right,key);
            return root;
        }
        else
        {
            if (!root->left) return root->right;
            else if (!root->right) return root->left;
            else
            {
                TreeNode* successorNode=root->right;
                while (successorNode->left)
                    successorNode=successorNode->left;
                root->val=successorNode->val;
                root->right=deleteNode(root->right,successorNode->val);
                return root;
            }
        }
    }
};