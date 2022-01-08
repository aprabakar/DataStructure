class Solution {
public:
    void insert(TreeNode* nodeToBeInserted,TreeNode* subTree){
        
        TreeNode* prev = NULL;
        TreeNode* root = subTree;
        
        if(!nodeToBeInserted){
            return;
        }
        
        while(true){
            if(!root){
                if(prev){
                    if(prev->val > nodeToBeInserted->val){
                        prev->left = nodeToBeInserted;
                    }else{
                        prev->right = nodeToBeInserted;
                    }
                }
                return;
            }
            prev = root;
            root = (root->val > nodeToBeInserted->val) ? root->left : root->right;
        }
        
        return;
        
    }
    
    TreeNode* deleteNodeUtil(TreeNode* root){
        if(root->left){
            TreeNode* temp = root->right;
            root = root->left;
            insert(temp,root);
        }else if(root->right){
            root = root->right;
        }else{
            root = NULL;
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {

        TreeNode* head = root; 
        
        while(root){
            
            if(root->val == key){
                head = deleteNodeUtil(root);
                break;
            } 
            
            if(root->left && root->left->val == key){
                root->left = deleteNodeUtil(root->left);
                break;
            }
            
            if(root->right && root->right->val == key){
                root->right = deleteNodeUtil(root->right);
                break;
            }  
            
            root = (root->val > key) ? root->left : root->right;
        }
        
        return head;
    }
};


// simple / traditional approach
class Solution {
public:
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root)  
            if(key < root->val){
               root->left = deleteNode(root->left, key);      
            } 
            else if(key > root->val){
              root->right = deleteNode(root->right, key);         
            } 
            else{
                if(!root->left && !root->right){
                  //No child condition  
                  return NULL;          
                } 
                if (!root->left || !root->right){
                   //One child contion -> replace the node with it's child 
                   return root->left ? root->left : root->right;    
                }
                    
				//Two child condition   	                                                
                TreeNode* temp = root->left;                 
                while(temp->right != NULL){
                  temp = temp->right;  
                } 
                root->val = temp->val;                            
                root->left = deleteNode(root->left, temp->val);  
                deleteNode(root->right, temp->val);		
            }
        return root;
    }
};
