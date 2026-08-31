/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL){return {};}
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* node = root;
        vector<int> ans;
        while (!s.empty()) {
            if (node == NULL) {
                node = s.top()->right;
                ans.push_back(s.top()->val);
                s.pop();
                if(node!=NULL){s.push(node);}
            } else {
                node = s.top()->left;
                if(node!=NULL){s.push(node);}
            }
        }

        return ans;
    }
};