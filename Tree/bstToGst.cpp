// For a particular node, all values greater than that lie in right sub-half.
class Solution {
public:
    int sum = 0;
    TreeNode* bstToGst(TreeNode* root) {
        
        if(root->right) bstToGst(root->right);

        sum+=root->val;
        root->val = sum;

        if(root->left) bstToGst(root->left);
        return root;
    }
};
