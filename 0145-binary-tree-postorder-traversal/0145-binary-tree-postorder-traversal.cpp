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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL){return {};}
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode* node = root;
        TreeNode* lastVisited = nullptr;
        s.push(root);
        while(!s.empty()){
            
            while(node!=NULL){
                node = node->left;
                if(node){s.push(node);}
            }

            TreeNode* temp = s.top();

            // to check if we have processed the right half or not
            if(temp->right && temp->right != lastVisited){
                node = temp->right;
                s.push(node);
            }
            // if not then we have processed the right and the left sub trees
            else{
                ans.push_back(temp->val);
                s.pop();
                lastVisited = temp;
            }
            
        }

        return ans;
    }
};