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

//Recursive Traversal
class Solution {
public:
    vector<int> result;
    vector<int> preorderTraversal(TreeNode* root) {
       if(!root){
            return result;
        }
        
        result.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return result;
    }
};

//Iterative Traversal

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
       stack<TreeNode*> st; 
       vector<int> result;
       
       if(!root){
           return result;
       }
        
       st.push(root);
       
       while(!st.empty()){
           result.push_back(st.top()->val);
           TreeNode* curr = st.top();
           st.pop();
           if(curr->right){
               st.push(curr->right);
           }

           if(curr->left){
               st.push(curr->left);
           }
       }
        
        return result;
    }
};
