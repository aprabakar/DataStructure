class Solution {
public:   
    vector<int> dp = vector<int>(46,0);
    int findWays(int remainVal){
        if(remainVal == 0 || remainVal == 1){
            return 1;
        }
        
        if(dp[remainVal]){
            return dp[remainVal];
        }
        
        dp[remainVal] = findWays(remainVal-1) + findWays(remainVal-2);
        return dp[remainVal];
    }    
    int climbStairs(int n) {
       return findWays(n);
    }
};
