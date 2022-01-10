class Solution {
public:
    TreeNode* depthPos = NULL;
    TreeNode* result = NULL;
    void findBottomLeftValueUtil(TreeNode* node, int depth){
        if(!node->left && !node->right){
            if(!depthPos){
                //TreeNode* temp= new TreeNode(depth);
                depthPos = new TreeNode(depth);
                result = new TreeNode(node->val);
            }else{
                if(depthPos->val < depth){
                   depthPos->val = depth;
                   result->val = node->val; 
                }
            }
            return;
        }
        
        if(node->left){
            findBottomLeftValueUtil(node->left,depth+1);
        }
        
        if(node->right){
           findBottomLeftValueUtil(node->right,depth+1); 
        }
        
        return;
        
    }
    int findBottomLeftValue(TreeNode* root) {
        findBottomLeftValueUtil(root,0);
        return result->val;
    }
};
