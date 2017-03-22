/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// recursive
class Solution {
public:
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        int rob_root, not_rob_root;
        _rob(root, &rob_root, &not_rob_root);
        return max(rob_root, not_rob_root);
    }
private:
    void _rob(TreeNode* node, int* rob_node, int* not_rob_node){
        int a = 0, b = 0, c = 0, d = 0;
        if(node->left){
            _rob(node->left, &a, &b);
        }
        if(node->right){
            _rob(node->right, &c, &d);
        }
        *rob_node = max(a, b) + max(c, d);
        *not_rob_node = node->val + a + c;
    }
};

class Solution_no_recursive{
public:
    int rob(TreeNode* root){
        if(!root)
            return 0;
        TreeNode* node = root;
        TreeNode* ln, *rn;
        while(node){}
    }
};