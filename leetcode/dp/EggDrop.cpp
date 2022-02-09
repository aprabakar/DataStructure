// Math
class Solution {
public:
    int twoEggDrop(int n) {
        if(n ==1 || n==2){
            return n;
        }
                
        int reduce = 1 ,count= 0;
        
        while(reduce <=n){
            n -= reduce;
            count++;
            reduce += 1;
            
            if(n == 0){
                count--;
            }
        }
        
        return count+1;
    }
};

// Top down DP
int dp[1001] = {};
class Solution {
public:
int twoEggDrop(int n) {
	if (dp[n] != 0){
       return dp[n]; 
    }
    for (int i = 1; i <= n; ++i){
       dp[n] = min(dp[n] == 0 ? n : dp[n], 1 + max(i - 1, twoEggDrop(n - i)));  
    }
	return dp[n];
    }
};
