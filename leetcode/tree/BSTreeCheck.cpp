// Approach 1 (Recursive)
class Solution {
public:
    bool isValidBSTUtil(TreeNode* node, TreeNode* currMinNode, TreeNode* currMaxNode){
        if(!node){
            return true;
        }
        
        if(currMinNode && node->val <= currMinNode->val){
            return false;
        } 
        
        if(currMaxNode && node->val >= currMaxNode->val){
            return false;
        }        
        
        
        return (isValidBSTUtil(node->left,currMinNode,node) &&
                isValidBSTUtil(node->right,node,currMaxNode));
       
    }
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
    
        return isValidBSTUtil(root, NULL,NULL);
    }
};


//Approach 2 (Iterative Inorder)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
       if (!root){
          return true;  
       } 
       stack<TreeNode*> st;
       TreeNode* pre = NULL;
       while (root || !st.empty()) {
          while (root) {
             st.push(root);
             root = root->left;
          }
          root = st.top();
          st.pop();
          cout<<"val = "<<root->val<<endl;
          if(pre){
             cout<<"pre = "<<pre->val<<endl; 
          }else{
              cout<<"pre = NIL"<<endl;
          } 
          if(pre && root->val <= pre->val){
            return false;  
          } 
          pre = root;
          root = root->right;
       }
      return true;        
    }
};
