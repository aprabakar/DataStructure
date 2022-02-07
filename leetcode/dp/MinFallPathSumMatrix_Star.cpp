// leet -> https://leetcode.com/problems/minimum-falling-path-sum/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();   
        vector<vector<int>> dp(m+1 , vector<int>(n+1,-101));
        
        int ans = 101;
        for(int j=0 ; j< n ; j++){
            dp[0][j] = matrix[0][j];
            ans = min(ans, dp[0][j]);
        }
        
        if(m == 1){
            return ans;
        }
        
        for(int i=1; i < m ; i++){
            for(int j=0 ; j <n ; j++){
                
                int leftTop, rightTop, top;
                leftTop = (j == 0) ? INT_MAX : dp[i-1][j-1];
                rightTop = (j == n-1) ? INT_MAX : dp[i-1][j+1];
                top = dp[i-1][j];
                    
                dp[i][j] = matrix[i][j] + min(top,min(leftTop , rightTop));
                
                if(i == m-1){
                    ans = (j==0) ? dp[i][j] : min(ans, dp[i][j]);
                }
            }
        }
        
        return ans;
    }
};
