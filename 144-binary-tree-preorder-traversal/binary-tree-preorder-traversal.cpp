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
    void preorder(TreeNode* root,vector<int>& arr) //preorder and store in arr
    {
        if (root==nullptr) return;
        arr.push_back(root->val);
        preorder(root->left,arr);
        preorder(root->right,arr);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> arr;
        preorder(root,arr);
        return arr;
    }

    /*
    vector<int> preOrder(Node* root){
    vector<int> arr;
    if (root == nullptr) return arr;

    arr.push_back(root->data);
    vector<int> left = preOrder(root->left);
    vector<int> right = preOrder(root->right);

    arr.insert(arr.end(), left.begin(), left.end());
    arr.insert(arr.end(), right.begin(), right.end());

    return arr;
    }
    */
};