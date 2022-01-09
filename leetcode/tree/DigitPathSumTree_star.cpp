//leet -> https://leetcode.com/problems/sum-root-to-leaf-numbers/

class Solution {
public:
    int result = 0;
    void traverse(TreeNode* node, int currVal, int mul){
        
        currVal = currVal * mul + node->val;
        if(!node->left && !node->right){
        
            result += currVal;
            return;
        }
        
        if(node->left){
           traverse(node->left,currVal,mul); 
        }
        
        if(node->right){
           traverse(node->right,currVal,mul); 
        }
        
        return;
        
    }
    int sumNumbers(TreeNode* root) {
        traverse(root,0,10);
        return result;
    }
};
