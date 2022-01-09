class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        deque<TreeNode*> qu;
        vector<int> result;
        
        if(!root){
            return result;
        }
        
        qu.push_back(root);
            
        while(!qu.empty()){
            int size = qu.size();
            bool isFirst = true;
            while(size--){
                
                TreeNode* curr = qu.front();
                qu.pop_front();
                
                if(isFirst){
                    result.push_back(curr->val);
                    isFirst = false;
                }
                
                if(curr->right){
                    qu.push_back(curr->right);
                }
                
                if(curr->left){
                    qu.push_back(curr->left); 
                } 
            }
        }
        
        return result;
    }
};

//Smart Approach

class Solution {
public:
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()<level) res.push_back(root->val);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }
    
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 1, res);
        return res;
    }
};
