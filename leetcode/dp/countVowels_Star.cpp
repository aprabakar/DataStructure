// leet -> https://leetcode.com/problems/count-vowels-permutation/

// Top Down
class Solution {
public:
    int mod = 1e9+7;
    unordered_map<string,int> dp;
    int countVowelPermutationUtil(int n, string currStr){
        
        cout<<"currStr = "<<currStr<<endl;
        if(n == 0){
            return 1;
        }
        
        if(dp.find(currStr) != dp.end()){
            return dp[currStr];
        }
        
        string currStrLastChar;
        currStrLastChar +=  currStr[currStr.size()-1];
        
        if(currStrLastChar == "a"){
            dp[currStr] = countVowelPermutationUtil(n-1,currStr + "e");
        }
        
        if(currStrLastChar == "e"){
            dp[currStr] =  countVowelPermutationUtil(n-1,currStr + "a") + 
                          countVowelPermutationUtil(n-1,currStr + "i");
        }
        
        if(currStrLastChar == "o"){
            dp[currStr] =  countVowelPermutationUtil(n-1,currStr + "i") + 
                           countVowelPermutationUtil(n-1,currStr + "u");            
        }
        
        if(currStrLastChar == "u"){
            dp[currStr] = countVowelPermutationUtil(n-1,currStr + "a");
        }
        
        int currTotal = 0;
        
        if(currStrLastChar == "i"){
            vector<string> temp_vowels{"a","e","o","u"};


            for(int i=0 ; i<4 ; i++){
               currTotal +=  countVowelPermutationUtil(n-1,currStr + temp_vowels[i]);
               currTotal %= mod;
            }   
            
            dp[currStr] = currTotal;
        }
  
        return dp[currStr];
    }
    int countVowelPermutation(int n) {
        vector<string> vowels{"a","e","i","o","u"};
        int ans = 0;
        
        for(int i=0 ; i<5 ; i++){
           ans +=  countVowelPermutationUtil(n-1,vowels[i]);
           ans %= mod;
           //cout<<"ans = "<<ans<<" vowel = "<<vowels[i]<<endl;
        }
        
        return ans;
    }
};



// Bottom Up
class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<long>> dp(n+1,vector<long>(6));
        int mod=1e9+7;
        
        for(int i=0 ; i<5; i++){
            dp[1][i] = 1;
        }
        
        int ans = 5;
        
        if(n == 1){
            return ans;
        }
        
        ans = 0;
        
        for(int i=2 ; i<=n ; i++){
            for(int j=0 ; j< 5; j++){
                if(j == 0){
                    dp[i][j] = dp[i-1][1] + dp[i-1][2] + dp[i-1][4];
                }else if(j == 1){
                    dp[i][j] = dp[i-1][0] + dp[i-1][2];
                }else if(j == 2){
                    dp[i][j] = dp[i-1][1] + dp[i-1][3];
                }else if(j == 3){
                    dp[i][j] = dp[i-1][2];
                }else if(j == 4){
                    dp[i][j] = dp[i-1][3] + dp[i-1][2];
                }
                
                dp[i][j] %= mod;
                
                if(i == n){
                    ans += dp[i][j];
                    ans %= mod;
                }                
            }
        }
        
        return ans;
    }
};


// a,e,i,o,u

// e,i,u = a
// a,i = e
// e,o = i
// i = o
// o,i = u



// Let dp[i][j] be the number of strings of length i that ends with the j-th vowel.

// dp[1][a] = 1
// dp[1][e] = 1
// dp[1][i] = 1
// dp[1][o] = 1
// dp[1][u] = 1

// dp[2][a] = 3
// dp[2][e] = 2
// dp[2][i] = 2
// dp[2][o] = 1
// dp[2][u] = 2

// dp[3][a] = 6
// dp[3][e] = 5
// dp[3][i] = 3
// dp[3][o] = 2
// dp[3][u] = 3
