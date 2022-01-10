// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        deque<TreeNode*> q;
        vector<int> result;
        
        if(!root){
            return result;
        }
        
        q.push_back(root);
        
        while(!q.empty()){
            int size = q.size();
            TreeNode* max_ele = NULL;
            
            while(size--){
                TreeNode* curr = q.front();
                q.pop_front();
                
                if(!max_ele){
                    max_ele = new TreeNode(curr->val);
                }else{
                    max_ele->val = max(max_ele->val , curr->val);
                }
                
                if(curr->left){
                    q.push_back(curr->left);
                }
                
                if(curr->right){
                    q.push_back(curr->right);
                }                
            }
            
            result.push_back(max_ele->val);
        }
        return result;
    }
};


// Time: O(N)
// Space: O(logN)
class Solution {
private:
  vector<int> ans;
  void preorder(TreeNode* root, int height) {
    if (!root) return;
    if (ans.size() < height) ans.push_back(root->val);
    else ans[height - 1] = max(ans[height - 1], root->val);
    preorder(root->left, height + 1);
    preorder(root->right, height + 1);
  }
public:
  vector<int> largestValues(TreeNode* root) {
    preorder(root, 1);
    return ans;
  }
};
