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
    TreeNode* solve(TreeNode* root,int node,int &minNode)
    {
        if(root == NULL)
            return NULL;
        
        
        
        TreeNode* left=solve(root->left,node+1,minNode);
        TreeNode* right=solve(root->right,node+1,minNode);
        
        if(left == NULL && right == NULL && node < minNode)
        {
            minNode=node;
        }
        return root;
    }
    
    int minDepth(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        int minNode=INT_MAX;        
        solve(root,1,minNode);
        return minNode;
    }
};