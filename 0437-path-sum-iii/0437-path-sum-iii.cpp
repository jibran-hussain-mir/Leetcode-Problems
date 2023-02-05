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
    void solve(TreeNode* root,int targetSum,int &count,vector<int> v)
    {
        if(root == NULL)
            return;
        
        v.push_back(root->val);
        
        solve(root->left,targetSum,count,v);
        solve(root->right,targetSum,count,v);
        
        long int sum=0;
        int size=v.size();
        for(int i=size-1;i>=0;i--)
        {
            sum+=v[i];
            if(sum == targetSum)
            {
                count++;
            }  
        }

    }
    
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        int count=0;
        solve(root,targetSum,count,v);
        return count;        
    }
};