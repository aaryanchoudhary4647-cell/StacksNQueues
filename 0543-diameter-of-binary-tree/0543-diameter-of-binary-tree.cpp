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
    // checking for the diameter for each N every node
    void diameter(TreeNode* node,int &ans){
        if(node==NULL){return;}

        int lh = height(node->left);
        int rh = height(node->right);

        ans = max(ans,lh+rh);
        diameter(node->left,ans);
        diameter(node->right,ans);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans =0;
        diameter(root,ans);
        return ans;
    }
};