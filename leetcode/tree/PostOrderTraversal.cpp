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

// // Recursive traversal;
class Solution {
public:
    vector<int> result;
    vector<int> postorderTraversal(TreeNode* root) {
       if(!root){
            return result;
        }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        result.push_back(root->val);
        return result;        
    }
};


// Iterative traversal
class Solution {
public:
vector<int> postorderTraversal(TreeNode* root) {
       stack<TreeNode*> st; 
       vector<int> result;
       
       while(!st.empty() || root != NULL){
           if(root != NULL){
               st.push(root);
               root = root->left;
           }else{
               TreeNode* currNodeRight = st.top()->right;
               if(currNodeRight){
                   root = currNodeRight;
               }else{
                   TreeNode* currNode = st.top();
                   st.pop();
                   result.push_back(currNode->val);
                   while(!st.empty() && currNode == st.top()->right){
                       currNode = st.top();
                       st.pop();
                       result.push_back(currNode->val);                       
                   }
               }
               
           }
       }
        return result;
    }
};
