// leet -> https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.length()+1,vector<int>(s.length()+1,0));
        int start,end,curr_max = INT_MIN;
        
        for(int i=s.length()-1 ; i >= 0; i--){
            for(int j = i ; j < s.length() ; j++){
                if(i == j){
                    dp[i][j] = 1;
                }else if(s[i] == s[j]){
                    if(i+1 == j){
                        dp[i][j] = 2;
                    }else if(dp[i+1][j-1] != 0){
                       dp[i][j] = 2 + dp[i+1][j-1]; 
                    }
                }
                
                if(dp[i][j] > curr_max){
                    curr_max = dp[i][j];
                    start = i;
                    end = j;
                }
            }
        }
        
        string ans = "";
        
        for(int i=start ; i <= end ; i++){
            ans += s[i];
        }
        return ans;
    }
};
