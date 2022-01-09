class Solution {
public:
    int maxDepthVal = -1;
    void preorderUtil(Node* node,int depth){
        if(!node){
            return;
        }
        maxDepthVal = max(maxDepthVal, depth);
        for(int i= 0 ; i< node->children.size();i++){
            preorderUtil(node->children[i], depth+1);
        }
        return;
        
    }    
    int maxDepth(Node* root) {
        preorderUtil(root,0);
        return maxDepthVal+1;
    }
};
