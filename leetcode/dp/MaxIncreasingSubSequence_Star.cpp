// leet-> https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       // 1 2 0 3 
       // 1 6 0 1 2 3 4
       // 2 5 3 7 10  
       // 5 4 0 3 
        
       int ans = 1; 
       vector<int> dp(nums.size()+1,1);
       dp[nums.size() -1] = 1; 
       for(int i= nums.size()-1; i >= 0 ; i--){
           for(int j= nums.size()-1 ; j > i; j--){
               if(nums[i] < nums[j]){
                   dp[i] = max(dp[i], dp[j] +1);
               }
               ans = max(ans, dp[i]);
           }
       }
        
       return ans;
    }
};
