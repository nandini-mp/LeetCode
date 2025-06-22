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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node=new TreeNode(val);
        if (!root) return root=node;
        TreeNode* temp=root;
        TreeNode* prev=NULL;
        while (temp!=NULL)
        {
            prev=temp;
            if (val<temp->val)
                temp=temp->left;
            else
                temp=temp->right;
        }
        if (val<prev->val)
            prev->left=node;
        else
            prev->right=node;
        return root;
    }
};