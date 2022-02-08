// leet ->  https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {

        if(target >  k*n)
            return 0;
        
        vector<vector<int>> dp(n+1, vector<int>(target+1));
        int mod = 1e9+7;
        
        dp[0][0] = 1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                int curr_target = j;
                int count = 0;
                for(int face=1;face<=k;face++){
                    if(curr_target-face < 0)
                        break;
                    count = (count+dp[i-1][curr_target-face]) % mod;
                }
                dp[i][j] = count;
            }
        }
        return dp[n][target];
    }
};
