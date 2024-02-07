// Recursion
int climbStairs(int n) {
    if(n < 0){
        return 0;
    }

    if(n == 0){
        return 1;
    }

    return climbStairs(n-1) + climbStairs(n-2);
}

//Top down or memorization
int solve(int n, vector<int>& dp){
    if(n < 0){
        return 0;
    }

    if(n == 0){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    return dp[n] = solve(n-1, dp) + solve(n-2, dp);
}
int climbStairs(int n) {
    vector<int> dp(n+1, -1);
    return solve(n, dp);
}

//Bottom up / tabulation
int climbStairs(int n) {
    vector<int> dp(n+1);
    
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2 ; i <= n ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

//Tabulation with space optimized
int climbStairs(int n) {
    int prev1 =1, prev2 =1;

    for(int i=2 ; i <= n ; i++){
        int curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;
}

//Two loops:
//https://leetcode.com/problems/word-break/
for(int i = 1; i <= n; i++){
    for(int j = 1; j <= i; j++){
        int len = i - j + 1;
        string str = s.substr(j - 1, len);
        if(st.find(str) != st.end()){
            dp[i] = (dp[i] || dp[j-1]);
        } 

        if(dp[i] == true){
            break;
        }
    }
}
return dp[n];

//DP on matrix
//https://leetcode.com/problems/unique-paths/description/
{    
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++) {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                temp[j] = 1;
                continue;
            }
            int up = 0;
            int left = 0;
            if (i > 0)
                up = prev[j];
            if (j > 0)
                left = temp[j - 1];
            temp[j] = up + left;
        }

        prev = temp;
    }
    return prev[n - 1];
}

// Different start and ending points
https://leetcode.com/problems/minimum-falling-path-sum/
int m = matrix.size();
int n = matrix[0].size();   
vector<int> prev(n , 0);

int ans = 101;
for(int j=0 ; j< n ; j++){
    prev[j] = matrix[0][j];
    ans = min(ans, prev[j]);
}

if(m == 1){
    return ans;
}

for(int i=1; i < m ; i++){
    vector<int> curr(n , 0);
    for(int j=0 ; j < n ; j++){
        int leftTop, rightTop, top;
        leftTop = (j == 0) ? INT_MAX : prev[j-1];
        rightTop = (j == n-1) ? INT_MAX : prev[j+1];
        top = prev[j];
         
        curr[j] = matrix[i][j] + min(top,min(leftTop , rightTop));
        
        if(i == m-1){
            ans = (j==0) ? curr[j] : min(ans, curr[j]);
        }
    }
    prev = curr;
}

return ans;        

//Problems:
//1D
https://leetcode.com/problems/house-robber/
https://leetcode.com/problems/house-robber-ii/
https://leetcode.com/problems/decode-ways/
https://leetcode.com/problems/coin-change/description/
https://leetcode.com/problems/maximum-product-subarray/
https://leetcode.com/problems/longest-increasing-subsequence/

//2D
https://leetcode.com/problems/longest-palindromic-substring/
https://leetcode.com/problems/palindromic-substrings/
https://leetcode.com/problems/unique-paths/description/
https://leetcode.com/problems/unique-paths-ii/
https://leetcode.com/problems/minimum-path-sum/description/
https://leetcode.com/problems/minimum-falling-path-sum/
