class Solution {
public:
    bool flag = true;
    int absDiff(int x, int y){
        return (x >= y) ? (x-y) : (y-x);
    }
    int isBalancedUtil(TreeNode* node){
        if(!node){
            return 0;
        }
        
        int leftSubTreeHeight = isBalancedUtil(node->left);
        int rightSubTreeHeight = isBalancedUtil(node->right);
        
        if(absDiff(leftSubTreeHeight, rightSubTreeHeight) > 1){
            flag = false;
        }
        
        return max(leftSubTreeHeight,rightSubTreeHeight)+1;
        
        
    }
    bool isBalanced(TreeNode* root) {
        isBalancedUtil(root);
        return flag;
    }
};
