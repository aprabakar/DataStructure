// leet ->  https://leetcode.com/problems/coin-change-2/

// Recursive
class Solution {
public:
    
    int coinChange(vector<int>& coins, int n, int amount)
    {
        if(n==0)
            return 0;
        if(amount == 0)
        {
            return 1;
        }
        if(coins[n-1] > amount)
        {
            return coinChange(coins, n-1, amount);
        }
        return coinChange(coins, n, amount-coins[n-1]) + coinChange(coins, n-1, amount);
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(amount == 0) {
            return 1;
        }
        if(n==0)
            return 0;
        return coinChange(coins, n, amount);
        
    }
};

// Top Down
class Solution {
public:
    vector<vector<int>> dp;
    int coinChange(vector<int>& coins, int n, int amount)
    {
        if(n==0)
            return 0;
        if(amount == 0)
        {
            return 1;
        }
        if(dp[n][amount] != -1)
        {
            return dp[n][amount];
        }
        if(coins[n-1] > amount)
        {
            dp[n][amount] = coinChange(coins, n-1, amount);
            return dp[n][amount];
        }
        dp[n][amount] = coinChange(coins, n, amount-coins[n-1]) + coinChange(coins, n-1, amount);
        return dp[n][amount];
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(amount == 0) {
            return 1;
        }
        if(n==0)
          return 0;
        
        dp.resize(n+2,vector<int>(amount+2,-1));
        
        dp[n][amount] = coinChange(coins, n, amount);
        return dp[n][amount];
        
    }
};


// Tabulatio  Bottom Up
class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(amount == 0) {
            return 1;
        }
        if(n==0)
          return 0;
        vector<vector<int>> dp;
        dp.resize(n+1,vector<int>(amount+1,-1));
        
        for(int i=0;i<n+1;i++)
        {
            dp[i][0] = 1;
        }
        
        for(int i=0;i<amount+1;i++)
        {
            dp[0][i] = 0;
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<amount+1;j++)
            {
                if(coins[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j]+dp[i][j-coins[i-1]];
                }
                //cout<<" coin= "<<coins[i-1]<< " j= "<<j<<" dp= "<<dp[i][j]<<endl;
            }
            
            //cout<<"---------"<<endl;
        }
        return dp[n][amount];
        
    }
};

