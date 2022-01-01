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

//Top Down Approach
class Solution {
public:
    int answer = 0;
    void maxDepthUtil(TreeNode* root, int depth){
        if(!root){
            return;
        }
        
        if(!root->left && !root->right){
            answer = max (answer, depth);
        }
        maxDepthUtil(root->left,depth+1);
        maxDepthUtil(root->right,depth+1);
    }
    int maxDepth(TreeNode* root) {
        maxDepthUtil(root,1);
        return answer;
    }
};

//Bottom up Approach
class Solution {
public:
    
    int maxDepthUtil(TreeNode* root, int depth){
        if(!root){
            return depth;
        }
        
        int left = maxDepthUtil(root->left,depth);
        int right = maxDepthUtil(root->right,depth);
        
        return max(left,right)+1;
    }
    int maxDepth(TreeNode* root) {
      return maxDepthUtil(root,0);
    }
};
