// leet- > https://leetcode.com/problems/decode-ways/

// Top Down Approach
class Solution {
public:
    vector<int> dp;
    int numDecodingsUtil(int currPos , string s, string currentStr){

        if(!currentStr.empty() && stoi(currentStr) > 26){
            return 0;
        }
        
        if(currPos <= s.size()-1){
            string currPosStr;
            currPosStr += s[currPos];

            if(stoi(currPosStr) == 0){
                return 0;
            }              
        }
      
        
        if(currPos >= s.size()-1){
            return 1;
        }
        
        if(dp[currPos] != 0){
            return dp[currPos];
        }
        

        
        string nextStringAlone;
        nextStringAlone += s[currPos+1];
        
        string nextStringCoupled;
        nextStringCoupled += s[currPos];
        nextStringCoupled += s[currPos+1];
        
        dp[currPos] = numDecodingsUtil(currPos+1,s,nextStringAlone) +
                      numDecodingsUtil(currPos+2,s,nextStringCoupled);
        
        return dp[currPos];
    }
    int numDecodings(string s) {
        dp.resize(s.length()+1,0);
        dp[s.length()] = numDecodingsUtil(0, s, "");
        return dp[s.length()];
    }
};


// Thank you so much for this clean and intuitive solution!!

// I wrote some notes for myself reference, hope it might help someone to understand this solution.

// dp[i]: represents possible decode ways to the ith char(include i), whose index in string is i-1

// Base case: dp[0] = 1 is just for creating base; dp[1], when there's one character, if it is not zero, it can only be 1 decode way. If it is 0, there will be no decode ways.

// Here only need to look at at most two digits before i, cuz biggest valid code is 26, which has two digits.

// For dp[i]: to avoid index out of boundry, extract substring of (i-1,i)- which is the ith char(index in String is i-1) and substring(i-2, i)

// First check if substring (i-1,i) is 0 or not. If it is 0, skip it, continue right to check substring (i-2,i), cuz 0 can only be decode by being together with the char before 0.

// Second, check if substring (i-2,i) falls in 10~26. If it does, means there are dp[i-2] more new decode ways.

// Time: should be O(n), where n is the length of String
// Space: should be O(n), where n is the length of String


// Tabulation Bottom Up Approach
class Solution {
public:
    
    int numDecodings(string s){
        if (s.length() == 0) {
            return 0;
        }
        
        int n = s.length();
        vector<int> dp (s.length()+1);
        dp[0] = 1;
        dp[1] = s[0] != '0' ? 1 : 0;
        for (int i = 2; i <= n; i++) {
            
            string firstStr, secondStr;
            firstStr += s[i-1];
            
            secondStr += s[i-2];
            secondStr += s[i-1];
            
            int first = stoi(firstStr);
            int second = stoi(secondStr);
            
            if (first >= 1 && first <= 9) {
               dp[i] += dp[i-1];  
            }
            if (second >= 10 && second <= 26) {
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};
