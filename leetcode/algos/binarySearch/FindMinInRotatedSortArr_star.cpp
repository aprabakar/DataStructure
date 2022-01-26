//leet -> https://leetcode.com/explore/learn/card/binary-search/126/template-ii/949/
class Solution {
public:
    int findMin(vector<int>& nums) {
         int left = 0 , right = nums.size() -1;
        
        if (nums.size() == 1) {
          return nums[left];
        }        
        
        if (nums[left] < nums[right]) {
          return nums[left];
        }        
        
        while(left <= right){
            int mid = (left +right) /2;
            
            // 2 3 1
            if(nums[mid] > nums[mid+1]){
                return nums[mid+1];
            }
            
            // 3 1 2
            if(mid-1 >=0 && nums[mid] < nums[mid-1]){
                return nums[mid];
            }
            
            
            if(nums[mid] < nums[nums.size() - 1]){
                // 1 2 3
                right = mid-1;
            }else{   
                // 1 2 3
                left = mid+1;
            }
                
        }
        
        return -1;
    }
};
