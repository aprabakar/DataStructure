// leet -> https://leetcode.com/explore/learn/card/binary-search/144/more-practices/1031/
class Solution {
public:
    int binarySearch(vector<int>& nums , int left , int right){
        if(left >= right || nums.size() == 1){
            return nums[left];
        }
              
        int mid = (left +right) /2;
        
        if(mid+1 < nums.size() && nums[mid] > nums[mid+1]){
            return nums[mid+1];
        }
        
        if(mid-1 >=0 && nums[mid] < nums[mid-1]){
            return nums[mid];
        }
        
        if(nums[mid] < nums[right]){
            return binarySearch(nums,left, mid-1);
        }
        
        if(nums[mid] > nums[right]){
           return binarySearch(nums,mid+1, right); 
        }
                
        return min(binarySearch(nums,left, mid-1) , binarySearch(nums,mid+1,right));
    } 
    
    int findMin(vector<int>& nums) {
         return binarySearch(nums,0, nums.size()-1);
    }
};
