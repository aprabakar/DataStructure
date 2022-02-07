// leet -> https://leetcode.com/problems/maximum-sum-circular-subarray/

// [2,-2,2,7,8,0]
// [2,-2,2,7,8,0,2,-2,2,7,8]
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curr_max = 0, curr_min = 0 , ans;
        int maxSubSum = -30001 , minSubSum = 30001 , totalSum = 0;
        
        //Case 1 , SubArr present in the non circular array
        for(int i=0 ; i< nums.size() ; i++){
            curr_max = max(nums[i], nums[i]+curr_max);
            maxSubSum = max(maxSubSum, curr_max);
            totalSum += nums[i];
        }
        
        
        //Case 2 , SubArr present in the circular array
        for(int i=0 ; i< nums.size(); i++){
            curr_min = min(nums[i], nums[i]+curr_min);
            minSubSum = min(minSubSum, curr_min);
        }
        
        minSubSum = totalSum - minSubSum;
        
        // case all negative integers
        if(minSubSum == 0){
            ans =  maxSubSum;
        }else{
            ans = max(maxSubSum,minSubSum);
        }
        
        return ans;
    }
};

