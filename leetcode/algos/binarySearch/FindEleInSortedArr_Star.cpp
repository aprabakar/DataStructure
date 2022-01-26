// leet-> https://leetcode.com/explore/learn/card/binary-search/125/template-i/952/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0 , right = nums.size() -1;
        
        while(left <= right){
            int mid = (left +right) /2;
            
            if(nums[mid] == target){
                return mid;
            }
            
            if(nums[right] == target){
                return right;
            }
            
            if(nums[left] == target){
                return left;
            }            
            
            
            // 5,6,7,0,1,2,3
            if(nums[mid] < nums[right]){
                if(target > nums[mid] && target < nums[right] ){
                    left = mid +1;
                }else{
                    right = mid-1;
                }
            }else{
                // 4,5,6,7,0,1,2
                if(target > nums[left] && target < nums[mid] ){
                   right = mid-1; 
                }else{
                   left = mid +1;
                }
            }
                
        }
        
        return -1;
    }
};
