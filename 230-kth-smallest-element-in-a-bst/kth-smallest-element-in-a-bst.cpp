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
    void inorder(TreeNode* root,int& counter,int k,int &result)
    {
        if (!root) return;
        inorder(root->left,counter,k,result); //visit left subtree
        if (result!=-1) return; //already got the result
        counter++; //visit current node
        if (counter==k)
        {
            result=root->val;
            return;
        }
        inorder(root->right,counter,k,result);
    }

    int kthSmallest(TreeNode* root, int k) {
       int counter=0,result=-1;
       inorder(root,counter,k,result);
       return result;
    }
};