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

    int height(TreeNode* node){
        if(node==NULL){return 0;}

        return 1+max(height(node->left),height(node->right));
    }

    bool isBalanced(TreeNode* root) {
        // checking that the current node is balanced
        if(root ==NULL){return true;}

        int lh = height(root->left);
        int rh = height(root->right);

        if(abs(lh-rh)>1){return false;}
        // checking of the further nodes
        bool lp = isBalanced(root->left);
        bool rp = isBalanced(root->right);

        if(!lp || !rp){return false;}

        return true;
    }
};