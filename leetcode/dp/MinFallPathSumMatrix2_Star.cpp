// First Leetcode hard complete solve
// leet -> https://leetcode.com/problems/minimum-falling-path-sum-ii/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();   
        vector<vector<int>> dp(n+1 , vector<int>(n+1,-101));
        
        if(n == 1){
            return grid[0][0];
        }
        
        for(int j=0 ; j< n ; j++){
            dp[0][j] = grid[0][j];
        }
        
        int ans;
        for(int i=1; i < n ; i++){
            for(int j=0 ; j <n ; j++){
                
                int prevRowMin = INT_MAX;
                for(int k = 0; k < n ; k++){
                    if(j == k){
                        continue;
                    }
                    prevRowMin = min(prevRowMin , dp[i-1][k]);
                }
                    
                dp[i][j] = grid[i][j] + prevRowMin;
                  
                if(i == n-1){
                    ans = (j==0) ? dp[i][j] : min(ans, dp[i][j]);
                }
            }
        }
        
        return ans;
    }
};
// 1 2 3
// 6 6 7
// 13 14 15    
