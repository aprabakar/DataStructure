// leet->  https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1);
        
        if(amount == 0){
            return 0;
        }
        
        sort(coins.begin(), coins.end());
        
        dp[0] = 0;
        for(int curr_amount=1 ; curr_amount<= amount ; curr_amount++){
            dp[curr_amount] = INT_MAX;
            
            for(int j=0 ; j< coins.size() ; j++){
                if(coins[j] > curr_amount){
                    break;
                }
                
                if (dp[curr_amount - coins[j]] != INT_MAX){
                    dp[curr_amount] = min(dp[curr_amount], 1 + dp[curr_amount - coins[j]]);
                }
            }
        }
                
     return (dp[amount] != INT_MAX) ? dp[amount] : -1;
    }
};
