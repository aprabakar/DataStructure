// leet- > https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_max = 0 , ans = INT_MIN;
        
        for(int i=0 ; i< nums.size() ; i++){
            curr_max = max(nums[i], nums[i]+curr_max);
            ans = max(ans, curr_max);
        }
        
        return ans;
    }
};
