//Recursive Approach

class Solution {
public:
    TreeNode* lcaNode = NULL;
    bool lowestCommonAncestorUtil(TreeNode* node , int p , int q){
        if(!node){
            return false;
        }
        
        
        bool lcaLeft = lowestCommonAncestorUtil(node->left,p,q);
        bool lcaRight = lowestCommonAncestorUtil(node->right,p,q);
        
        //cout<<"node->val = "<<node->val<<endl;
        if(lcaLeft && lcaRight){
           //cout<<"both";
           lcaNode = node;
           return true;  
        }        
        
        if(lcaLeft || lcaRight){
           //cout<<"single";
           if(node->val == p || node->val == q){
             lcaNode = node;
           }
           return true; 
        }
        
        if(node->val == p || node->val == q){
            return true; 
        }

        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lowestCommonAncestorUtil(root,p->val,q->val);
        return lcaNode;
    }
};
