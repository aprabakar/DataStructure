// Invert tree

if(!root){
    return root;
}

TreeNode* ltree= invertTree(root->left);
TreeNode* rtree = invertTree(root->right);
root->left = rtree;
root->right = ltree;
return root;

// trim tree
//https://leetcode.com/problems/trim-a-binary-search-tree/
TreeNode* trimBST(TreeNode* root, int low, int high) {
if (!root) return root;
if (root->val >= L && root->val <= R) {
    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);
    return root;
}
if (root->val < L)
    return trimBST(root->right, L, R);
return trimBST(root->left, L, R);
}

// Tree traversal with pair
TreeNode* ans = NULL;
pair<bool, bool> solve(TreeNode* node, int p, int q){
    if(!node){
        return make_pair(false, false);
    }

    bool isP = false, isQ = false;
    if(node->val == p){
        isP = true;
    }else if(node->val == q){
        isQ = true;
    }

    pair<bool, bool> lTree = solve(node->left, p, q);
    pair<bool, bool> rTree = solve(node->right, p, q);

    isP = isP || lTree.first || rTree.first;
    isQ = isQ || lTree.second || rTree.second;

    if(isP && isQ && !ans){
        ans = node;
        return make_pair(isP, isQ);
    }

    return make_pair(isP, isQ);
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    solve(root, p->val, q->val);
    return ans;
}

//Construct Binary Tree from Preorder and Inorder Traversal

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        int n = preorder.size();
        int m = inorder.size();

        TreeNode* root = build(preorder, 0, n - 1, inorder, 0, m - 1, mp);
        return root;
    }

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, 
    vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& mp) {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = mp[root->val];
        int numLeft = inRoot - inStart;

        root->left = build(preorder, preStart + 1, preStart + numLeft, inorder, inStart, inRoot - 1, mp);
        root->right = build(preorder, preStart + numLeft + 1, preEnd, inorder, inRoot + 1, inEnd, mp);

        return root;
    }
};
