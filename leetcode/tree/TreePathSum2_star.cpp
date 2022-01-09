//leet -> https://leetcode.com/problems/path-sum-ii/

class Solution {
public:
    vector<vector<int>> result;
    void pathSumUtil(TreeNode* node , int currSum, int targetSum , vector<int>& currPath){
        if(!node){
            return;
        }
        
        currSum = currSum + node->val;
        currPath.push_back(node->val);
        
        if(currSum == targetSum && !node->left && !node->right){
            result.push_back(currPath);
            currPath.pop_back();
            return;
        }
        
        if(node->left){
            pathSumUtil(node->left,currSum,targetSum,currPath);
        }
        
        if(node->right){
            pathSumUtil(node->right,currSum,targetSum,currPath);
        }
        
        currPath.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        pathSumUtil(root,0,targetSum,temp);
        return result;
    }
};
