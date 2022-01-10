class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        deque<TreeNode*> q;
        bool isEven = true;
        int preVal = 0;
        
        q.push_back(root);
            
        while(!q.empty()){
            int size = q.size();

            while(size--){

                TreeNode* curr = q.front();
                q.pop_front();

                if(isEven){
                    if(curr->val <= preVal || curr->val%2 == 0){
                        return false;
                    }
                }else{
                    if(curr->val >= preVal || curr->val%2 == 1){
                        return false;
                    }                        
                }

                preVal = curr->val;

                if(curr->left){
                    q.push_back(curr->left);
                }

                if(curr->right){
                    q.push_back(curr->right);
                }                    
            }

            isEven = !isEven;
            preVal = (isEven) ? 0 : INT_MAX;
        }
        
        return true; 
    }
};
