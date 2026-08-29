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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL){return {};}
        // root left right
        stack<TreeNode*> s;
        s.push(root);
        vector<int> ans;
        while(!s.empty()){
            TreeNode* node = s.top();
            s.pop();
            if(node->right){s.push(node->right);} // as stack will first remove the last element
            if(node->left){s.push(node->left);}
            ans.push_back(node->val);

        }

        return ans;



    }
};