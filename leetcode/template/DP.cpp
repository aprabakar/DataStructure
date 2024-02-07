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

//Problems:
//1D
https://leetcode.com/problems/house-robber/
https://leetcode.com/problems/house-robber-ii/
https://leetcode.com/problems/decode-ways/

//2D
https://leetcode.com/problems/longest-palindromic-substring/
https://leetcode.com/problems/palindromic-substrings/
