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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      deque<TreeNode*> doubleEndQueue;
        if(root)  doubleEndQueue.push_back(root);
        bool reverse = false;
        vector<vector<int>> zigzagResult;
        while(!doubleEndQueue.empty()){
            int size = doubleEndQueue.size();
            zigzagResult.push_back(vector<int>());
            for(int i=0; i<size; i++){
                if(!reverse){
                    auto node = doubleEndQueue.front();
                    zigzagResult.back().push_back(node->val);
                    doubleEndQueue.pop_front();
                    if(node->left)  doubleEndQueue.push_back(node->left);
                    if(node->right)  doubleEndQueue.push_back(node->right);
                }
                else{
                    auto node = doubleEndQueue.back();
                    zigzagResult.back().push_back(node->val);
                    doubleEndQueue.pop_back();
                    if(node->right)  doubleEndQueue.push_front(node->right);
                    if(node->left)  doubleEndQueue.push_front(node->left);                   
                }

            }
            reverse = !reverse;
        }
      return zigzagResult;
    }
};
