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
    bool hasPathSumUtil(TreeNode* root, int targetSum , int currSum){
        
        //Base cases
        if(!root){
            return false;
        }
        
        if(!root->left && !root->right){
            if(targetSum == currSum+root->val){
                return true;
            }
            return false;
        }
        
        return hasPathSumUtil(root->left,targetSum, currSum+root->val) ||  hasPathSumUtil(root->right,targetSum, currSum+root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
         if(!root){
             return false;
         }
        return hasPathSumUtil(root,targetSum,0);
    }
};
