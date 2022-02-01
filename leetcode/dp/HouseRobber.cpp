class Solution {
public:
    int rob(vector<int>& nums) {
        int first_val = 0 , second_val = nums[0] , ans = nums[0];
        
        for(int i = 1 ; i< nums.size() ; i++){
            ans = max(nums[i] + first_val, second_val);
            first_val = second_val;
            second_val = ans;
        }
        
        return ans;
    }
};
