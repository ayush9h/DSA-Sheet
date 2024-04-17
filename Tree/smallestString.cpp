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
    void helper(TreeNode* root, string s, string& ans)
    {
        if(!root)
            return;

        s+=('a' + root->val);
        helper(root->left,s,ans);

        if(!root->left && !root->right)
        {
            string temp = s;
            reverse(temp.begin(),temp.end());
            if(ans.empty() || ans > temp)
            {
                ans = temp;
            }
        }

        helper(root->right,s,ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans,s;

        helper(root,s,ans);

        return ans;
    }
};
