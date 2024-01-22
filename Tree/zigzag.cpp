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
        if(!root) return 0;

        int lHeight = height(root->left);
        int rHeight = height(root->right);

        return max(lHeight,rHeight) + 1;
    }
    void solve(TreeNode*root, int level,bool order, vector<int> &ans)
    {
        if(!root) return;

        if(level==1)
        {
            ans.push_back(root->val);
            return;
        }

        if(order)
        {
            solve(root->left,level-1,order,ans);
            solve(root->right,level-1,order,ans);
        }
        else{
            solve(root->right,level-1,order,ans);
            solve(root->left,level-1,order,ans);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int h = height(root);
        vector<vector<int>> res;

        bool order = true;

        for(int i = 1;i<h + 1;i++)
        {
            vector<int>ans;
            solve(root,i,order,ans);
            res.push_back(ans);
            order = !order;
        }
        return res;
    }
};
