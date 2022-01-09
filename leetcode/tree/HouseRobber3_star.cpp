//leet -> https://leetcode.com/problems/house-robber-iii/

//DP + memo solution top down
class Solution {
public:

    unordered_map<TreeNode*,int> memo;
    
    int helper(TreeNode* root) {
        if (root == NULL) return 0;
        
        if (memo.count(root)){
            return memo[root];
        } 
    
        int ans_including_root = root->val;
    
        if (root->left != NULL) {
              ans_including_root += helper(root->left->left) + helper(root->left->right);
        }
    
        if (root->right != NULL) {
              ans_including_root += helper(root->right->left) + helper(root->right->right);
        }
        
        int ans_excluding_root = helper(root->left) + helper(root->right);
    
        int ans = max(ans_including_root , ans_excluding_root);
        
        memo[root]=ans;
    
        return ans;
    }
    
    int rob(TreeNode* root) {
        return helper(root);
    }
};

// DP without memo bottom up
//We will return the Pair here, {case_when_curr_root_is_chosen, case_when_not_chosen} ...
//Let's assume any particular node (H), gets the answer from it's left child as {a,b} and right //child as{x,y} ....
//So , b is the case when H->left was not included and y is the case when H->right was not included... So, if we are gonna rob the House (H) , then total money we can get, p == H->val +y+b
//And when House will be not robbed then maximum money robbed, q == max(a,b) + max(c,d)..... and what this node H will return is {p,q}

class Solution {
public:

    unordered_map<TreeNode*,int> memo;
    
    pair<int,int> max_money_robbed(TreeNode* root){
        
        if(root==NULL)return {0,0};
        
        pair<int,int>left = max_money_robbed(root->left);
        pair<int,int>right = max_money_robbed(root->right);
        
        int root_house_robbed = left.second + right.second + root->val;
        int root_house_not_robbed = max(left.first,left.second)+ max(right.first,right.second);
        
        pair<int,int>ans;
        
        ans.first = root_house_robbed, ans.second = root_house_not_robbed;
        
        return ans;
        
    }
    
    int rob(TreeNode* root) {
        pair<int,int> result = max_money_robbed(root);
        return max(result.first, result.second);
    }
};
