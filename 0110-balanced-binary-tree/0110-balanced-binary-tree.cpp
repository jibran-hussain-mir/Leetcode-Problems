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
//     int height(TreeNode* root)
//     {
//         if(root == NULL)
//             return 0;
        
//         int leftSubtree=height(root->left);
//         int rightSubtree=height(root->right);
        
//         int ans=max(leftSubtree,rightSubtree)+1;
        
//         return ans;
//     }
    
//     bool isBalanced(TreeNode* root) {
//         if(root == NULL)
//             return true;
//         bool left=isBalanced(root->left);
//         bool right=isBalanced(root->right);
        
//         bool diff=abs(height(root->left)-height(root->right)) <= 1;
        
//         if(left && right && diff)
//             return true;
//         return false;
//     }
    
    pair<bool,int> check(TreeNode* root)    
    {
        if(root == NULL)
        {
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        
        pair<bool,int> left=check(root->left);
        pair<bool,int> right=check(root->right);
        bool diff=abs(left.second-right.second) <= 1;

        
        pair<bool,int> ans;
        if(left.first && right.first && diff)
        {
            ans.first=true;
        }
        ans.second=max(left.second,right.second)+1;
        return ans;
    }
    
    bool isBalanced(TreeNode* root)
    {
        return check(root).first;
    }
};