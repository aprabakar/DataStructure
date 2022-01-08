//Recursive
class Solution {
public:
    TreeNode* insertIntoBSTUtil(TreeNode* curr,TreeNode* prev,int val){
        
       if(!curr){
           TreeNode* newNode = new TreeNode(val);
            if(prev){
                if(prev->val > val){
                    prev->left = newNode;
                }else{
                    prev->right = newNode;
                }
            }
            return newNode;
        }
                
        if(curr->val > val){
            curr->left = insertIntoBSTUtil(curr->left,curr,val);
        }else{
            curr->right = insertIntoBSTUtil(curr->right,curr,val);
        }
        
        return curr;
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insertIntoBSTUtil(root,NULL,val);
    }
};

//Iterative
class Solution {
public:
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        TreeNode* prev = NULL;
        TreeNode* head = root;
        while(true){
            if(!root){
                if(!prev){
                   head = newNode; 
                }else{
                    if(prev->val > val){
                        prev->left = newNode;
                    }else{
                        prev->right = newNode;
                    }
                }
                break;
            }
            prev = root;
            root = (root->val > val) ? root->left : root->right;
            
        }
        return head;
    }
};
