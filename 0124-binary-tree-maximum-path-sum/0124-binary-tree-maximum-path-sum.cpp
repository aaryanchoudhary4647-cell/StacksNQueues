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

    int maxSum(TreeNode* node,int &mxSum){
        if(node==NULL){return 0;}

        int ls = max(0,maxSum(node->left,mxSum));
        int rs = max(0,maxSum(node->right,mxSum));

        mxSum = max(mxSum,ls+rs+node->val); // for a particular node what is the maxsum including that node

        return node->val + max(ls,rs); // we return this and not node->val+ rs+ls becoz that will automatically calculated further and here we have to return sum of a open network for ex here we are returning 20+15= 35 for node->right where node=-10 and not 20+15+7 becoz that will be a closed network
    }

    int maxPathSum(TreeNode* root) {
        int mxSum = INT_MIN;
        maxSum(root,mxSum);

        return mxSum;
    }

    
};