
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        inorder(root, nodes);
        return buildBST(nodes, 0, nodes.size() - 1);
    }
private:
    void inorder(TreeNode* node, vector<TreeNode*>& nodes) {
  
        if (node == NULL) return;

        inorder(node->left, nodes);
        nodes.push_back(node);
        inorder(node->right, nodes);
    }
    TreeNode* buildBST(vector<TreeNode*>& nodes, int left, int right) {
        if (left > right) return NULL;

        int mid = left + ((right - left) >> 1);
        TreeNode* node = nodes[mid];
        node->left = buildBST(nodes, left, mid - 1);
        node->right = buildBST(nodes, mid + 1, right);
        return node;
    }
};


// First do the inroder traversal, to get the nodes in increasing order and then take mid of them, and assign mid - 1 to left and mid + 1 to right recursively.
