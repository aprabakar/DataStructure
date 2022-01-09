//leet -> https://leetcode.com/problems/recover-binary-search-tree/

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
class Solution {
public:
     TreeNode* firstElement = NULL;
     TreeNode* secondElement = NULL;
     TreeNode* prevElement = NULL;
     void traverse(TreeNode* root) {
        
        if (root == NULL)
            return;
            
        traverse(root->left);
        
        // If first element has not been found, assign it to prevElement 
        if (firstElement == NULL && (prevElement != NULL && prevElement->val >= root->val)) {
            firstElement = prevElement;
        }
    
        // If first element is found, assign the second element to the root 
        if (firstElement != NULL && prevElement->val >= root->val) {
            secondElement = root;
        }        
        prevElement = root;

        traverse(root->right);   
    }
    
    void recoverTree(TreeNode* root) {
        
        // In order traversal to find the two elements
        traverse(root);
        
        // Swap the values of the two nodes
        int temp = firstElement->val;
        firstElement->val = secondElement->val;
        secondElement->val = temp;
    }
};
