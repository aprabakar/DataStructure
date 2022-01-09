class Solution {
public:
    TreeNode* createBST(vector<int>& nums, int start, int end){
        if(start > end){
            return NULL;
        }
        
        int mid = (start + end) / 2;
        TreeNode* newNode = new TreeNode(nums[mid]);
        newNode->left = createBST(nums,start,mid-1);
        newNode->right = createBST(nums,mid+1,end);
        return newNode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBST(nums,0,nums.size()-1);   
    }
};
