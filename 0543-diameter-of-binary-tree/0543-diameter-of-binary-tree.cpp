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

    int diameter(TreeNode* node,int ans){
        if(node==NULL){return 0;}

        int lh = height(node->left);
        int rh = height(node->right);

        int ls = diameter(node->left,ans);
        int rs = diameter(node->right,ans);
        ans = max(ls,rs);
        ans = max(ans,lh+rh);
        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans =0;

        return diameter(root,ans);
    }
};