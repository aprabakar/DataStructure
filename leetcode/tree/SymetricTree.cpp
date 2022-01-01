/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//Recursive solution

class Solution {
public:
    bool isSymmetricUtil(TreeNode* leftNode ,TreeNode* rightNode) {
        if(!leftNode && !rightNode){
            return true;
        }
        
        if(!leftNode || !rightNode){
            return false;
        }
        
        if(leftNode->val != rightNode->val){
            return false;
        }
        
        
        bool leftExtreme = isSymmetricUtil(leftNode->left,rightNode->right);
        bool centerPart = isSymmetricUtil(leftNode->right,rightNode->left);
        
        return leftExtreme && centerPart;
        
    }
    bool isSymmetric(TreeNode* root) {
        return isSymmetricUtil(root->left,root->right); 
    }
};

//Iterative Solution
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> bfsQ;
        
        if(!root){
            return true;
        }
        
        bfsQ.push(root);
        
        while(!bfsQ.empty()){
            int size = bfsQ.size();
            int count = 0;
            stack<int> st;
            
            while(count < size){
                
                TreeNode* curr = bfsQ.front();
                bfsQ.pop();
                
                if(count < size/2 && size != 1){
                    st.push(curr->val);
                }else if(count >= size/2 && size != 1){
                    if(!st.empty() && st.top() == curr->val){
                        st.pop();
                    }else{
                        return false;
                    }
                }
                
                if(curr->val != -200){
                    if(curr->left){
                        bfsQ.push(curr->left);
                    }else{
                        TreeNode* temp = new TreeNode(-200);
                        bfsQ.push(temp);
                    }

                    if(curr->right){
                        bfsQ.push(curr->right);         
                    }else{
                        TreeNode* temp = new TreeNode(-200);
                        bfsQ.push(temp);
                    }                    
                }
                
                
                count++;
            }
        }
        return true; 
    }
};


//Iterative Solution Better Approach
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
       if (!root) return true;
        queue<TreeNode*> check;
        
        check.push(root->left);
        check.push(root->right);
        
        while (!check.empty()) {
            TreeNode* node1 = check.front();
            check.pop();
            TreeNode* node2 = check.front();
            check.pop();
            if (!node1 && node2) return false;
            if (!node2 && node1) return false;
            if (node1 && node2) {
                if (node1->val != node2->val) return false;
                check.push(node1->left);
                check.push(node2->right);
                check.push(node1->right);
                check.push(node2->left);
            }
        }
        
        return true;
            
    }
};
