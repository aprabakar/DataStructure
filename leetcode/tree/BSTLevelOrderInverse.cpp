class Solution {
public:
    
    int depth(TreeNode *root) {
        if (!root) return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        deque<TreeNode*> qu;
        
        int pos = 1;
        int height = depth(root);
        vector<vector<int>> result(height,vector<int> {});
        
        if(!root){
            return result;
        }
        
        qu.push_back(root);
        
        while(!qu.empty()){
            int size = qu.size();
            vector<int> curr_result;
            
            while(size--){
                TreeNode* curr = qu.front();
                qu.pop_front();
                curr_result.push_back(curr->val);
                
                if(curr->left){
                    qu.push_back(curr->left);
                }
                
                if(curr->right){
                    qu.push_back(curr->right);
                }                
            }
            
            result[height - pos] = curr_result;
            pos++;
        }
        
        //reverse(result.begin(),result.end());
        return result;
        
    }
};
