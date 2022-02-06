//leet -> https://leetcode.com/problems/word-break/

class Solution {
public:
    
    bool isMatch(string s,int start, int end, string word){
        if((end-start) != word.length()-1){
            return false;
        }
        
        for(int i= start, j=0 ; i <= end; i++,j++){
            if(s[i] != word[j]){
                return false;
            }
        }
        
        return true;
    }
    
    bool prevSubStringMatch(int i, vector<bool>& dp){
        if(i < 0){
            return true;
        }
        
        return dp[i];
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.length()+1, false);
        
        for(int i =0 ; i<s.length() ; i++){
            for(string word: wordDict){
                int startIndex = (i-word.length())+1;
                
                if(word[word.length()-1] == s[i] && startIndex >= 0){
                    int endIndex = i;
                    if(isMatch(s,startIndex,endIndex,word) && 
                       prevSubStringMatch((startIndex-1) , dp)){
                        dp[endIndex] = true;
                    }
                }
            }
        }
        
        return dp[s.length()-1];
    }
};
