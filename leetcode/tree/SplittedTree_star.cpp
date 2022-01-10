// leet -> https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

class Solution {
public:
    long total_sum = 0;
    long max_product = 0;
    int mod = 1000000007;
    void dfs(TreeNode* node){
        if(!node){
            return;
        }
        
        dfs(node->left);
        dfs(node->right);
        total_sum += node->val;
        return;
    }
    
    int findMaxProduct(TreeNode* node){
        if(!node){
            return 0;
        }
        
        int lTreeSum = findMaxProduct(node->left);
        int rTreeSum = findMaxProduct(node->right);
        
        int curr_sum = node->val + lTreeSum + rTreeSum;
        int remain_sum = total_sum - curr_sum;
        
        max_product = max(max_product , (long) curr_sum * remain_sum);
        
        return curr_sum;
    }
    
    int maxProduct(TreeNode* root) {
        dfs(root);
        findMaxProduct(root);
        return max_product % mod;
    }
};
