// leet -> https://leetcode.com/problems/find-peak-element/

// My Approach
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        long left = 0 , right = nums.size()-1, mid , ans;
        
        while (left <= right){
           mid =  (left + right) / 2;
           
           if(mid-1 >= 0 && mid+1 < nums.size()){
               if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                   ans = mid;
                   break;                       
               }
               
               if(nums[mid+1] > nums[mid]){
                    left = mid+1;
               }else{
                    right = mid-1;
               }
           }else{
                // case : [1]
                if(mid-1 < 0 && mid+1 >= nums.size()){
                    ans = mid;
                    break;
                }
               
                if(mid-1 < 0){
                    ans = (nums[mid] > nums[mid+1]) ? mid : mid+1;
                }else if(mid+1 >= nums.size()){
                    ans = (nums[mid] > nums[mid-1]) ? mid : mid-1;
                }else{
                    ans = mid;
                }
                break;               
           }            
        }       
        
        return ans;
    }
};

// Simpler Approach

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        long left = 0 , right = nums.size()-1, mid;
        
        while (left < right){
           mid =  (left + right + 1) / 2;
           if(nums[mid] > nums[mid-1]){
               left = mid;
           }else{
               right = mid-1;
           }
        }
        
        return left;
    }
};
