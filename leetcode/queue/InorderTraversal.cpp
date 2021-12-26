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
    
    // Recursive solution
    
    // void inorderTraversalUtil(TreeNode* node){
    //     if(node == NULL){
    //         return;
    //     }
    //     inorderTraversalUtil(node->left);
    //     result.push_back(node->val);
    //     inorderTraversalUtil(node->right);    
    // }
    
    // Iterative solution
    
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        while(!st.empty() || root != NULL){
            while(root != NULL){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            result.push_back(root->val);
            root = root->right;
        }
        //inorderTraversalUtil(root);
        return result;
    }
};
