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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> bfsQ;
        vector<vector<int>> result;
        vector<int> levelNodes;
        
        if(!root){
            return result;
        }
        
        bfsQ.push(root);
        
        while(!bfsQ.empty()){
            int size = bfsQ.size();
            levelNodes.clear();
            while(size--){
                TreeNode* curr = bfsQ.front();
                bfsQ.pop();
                levelNodes.push_back(curr->val);
                if(curr->left){
                    bfsQ.push(curr->left);
                }
                
                if(curr->right){
                    bfsQ.push(curr->right);
                }                
            }
            result.push_back(levelNodes);
        }
        return result; 
    }
};
