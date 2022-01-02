class Solution {
public:
  TreeNode* buildTreeUtil(vector<int>& postorder, int postStart, int postEnd, 
                          vector<int>& inorder, int inStart, int inEnd, map<int, int> &inMap) {
        if(postStart > postEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = inMap[root->val];
        int numsRight = inEnd - inRoot;
      
        root->left = buildTreeUtil(postorder, postStart, postEnd-numsRight - 1, 
                                   inorder, inStart, inRoot - 1, inMap);      
        root->right = buildTreeUtil(postorder, postEnd - numsRight, postEnd - 1, 
                                    inorder, inRoot + 1, inEnd, inMap);



        return root;
    }    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inMap; 

        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }       

        TreeNode* root = buildTreeUtil(postorder, 0, postorder.size() - 1, 
                                       inorder, 0, inorder.size() - 1, inMap);
        return root;
    }
};
