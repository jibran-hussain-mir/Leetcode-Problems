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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans ;
        bool count=true;
       
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            vector<int> v;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* x=q.front();
                if(count == true)
                {
                    v.push_back(x->val);
                }
                else
                {
                    v.insert(v.begin(),x->val);
                }
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
                q.pop();
            }
            count=!count;
            ans.push_back(v);
            
        }
        return ans;
    }
};