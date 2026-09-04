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

    int recursive(TreeNode* node){
        if(node->right==NULL && node->left==NULL){return 1;}

        int a=0;
        int b=0;
        if(node->left){a=recursive(node->left);}
        if(node->right){b=recursive(node->right);}

        return 1+max(a,b);
    }

    int maxDepth(TreeNode* root) {
        if(root==NULL){return 0;}
        return recursive(root);
    }
};