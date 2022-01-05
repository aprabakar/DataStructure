class Solution {
public:
        int helper(TreeNode *root, int parent, int &res){
        if(!root) return 0;
        int lc = helper(root->left, root->val, res);
        int rc = helper(root->right, root->val, res);
        res = max(res, lc + rc);
        if(root->val == parent){
            return 1 + max(lc,rc);
        }else{
            return 0;
        }
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        helper(root,0,res);
        return res;
    }
};
