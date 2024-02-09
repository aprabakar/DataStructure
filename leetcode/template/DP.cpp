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

//3D 
https://leetcode.com/problems/cherry-pickup-ii/description/
{  
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> front(m, vector<int>(m, 0));
    vector<vector<int>> cur(m, vector<int>(m, 0));

    
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2)
                front[j1][j2] = grid[n - 1][j1];
            else
                front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    
    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int maxi = INT_MIN;

                
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ans;

                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        
                        if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
                            ans += -1e9; 
                        else
                            ans += front[j1 + di][j2 + dj]; 

                        maxi = max(ans, maxi); 
                    }
                }
                cur[j1][j2] = maxi; 
            }
        }
        front = cur; 
    }

    
    return front[0][m - 1];  
}

int n;
int target;
map<pair<int,int>,int> cache;
int DFS(vector<int>& nums,int currSum, int i)
{
    auto find = cache.find({i,currSum});
    
    if (find != cache.end())
        return find->second;
    
    if (i == n && currSum == target)
    {
        return 1;
    }
    if(i >= n)
        return 0;

    return cache[{i,currSum}] = DFS(nums,currSum + nums[i],i + 1) + DFS(nums,currSum - nums[i],i + 1);
}

int findTargetSumWays(vector<int>& nums, int S) 
{
    n = nums.size();
    target = S;
    
    if(n == 0)
        return 0;
    
    return DFS(nums,0,0);
}

//Problems:
//1D
https://leetcode.com/problems/house-robber/
https://leetcode.com/problems/house-robber-ii/
https://leetcode.com/problems/decode-ways/
https://leetcode.com/problems/coin-change/description/
https://leetcode.com/problems/maximum-product-subarray/
https://leetcode.com/problems/longest-increasing-subsequence/
https://leetcode.com/problems/partition-equal-subset-sum/
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
https://leetcode.com/problems/longest-increasing-subsequence/description/


//2D
https://leetcode.com/problems/longest-palindromic-substring/
https://leetcode.com/problems/palindromic-substrings/
https://leetcode.com/problems/unique-paths/description/
https://leetcode.com/problems/unique-paths-ii/
https://leetcode.com/problems/minimum-path-sum/description/
https://leetcode.com/problems/minimum-falling-path-sum/
https://leetcode.com/problems/cherry-pickup-ii/description/
https://leetcode.com/problems/target-sum/description/
https://leetcode.com/problems/coin-change-ii/
https://leetcode.com/problems/longest-common-subsequence/description/
https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
https://leetcode.com/problems/longest-palindromic-subsequence/description/
https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
https://leetcode.com/problems/delete-operation-for-two-strings/description/
https://leetcode.com/problems/shortest-common-supersequence/
https://leetcode.com/problems/distinct-subsequences/description/
https://leetcode.com/problems/edit-distance/


//3D
https://leetcode.com/problems/cherry-pickup-ii/description/

//1d with binary search
https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/
