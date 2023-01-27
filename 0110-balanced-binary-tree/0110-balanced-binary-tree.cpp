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
        if(root == NULL)
            return 0;
        
        int leftSubtree=height(root->left);
        int rightSubtree=height(root->right);
        
        int ans=max(leftSubtree,rightSubtree)+1;
        
        return ans;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        int left=isBalanced(root->left);
        int right=isBalanced(root->right);
        
        int diff=abs(height(root->left)-height(root->right)) <= 1;
        
        if(left && right && diff)
            return true;
        return false;
    }
};