// leet -> https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int> map;
        int prevPos = 0;
        int result = INT_MIN;
        int currResult = 0;
        
        if(s.size() <=1){
            return s.size();
        }
        
        for(int i = 0 ; i< s.size() ; i++){            
            // aabaabzbb
            if(map.count(s[i])){
                prevPos = max(map[s[i]] + 1, prevPos);
                
            }
            currResult = i- prevPos + 1;
            result = max(result, currResult);
            map[s[i]] = i;
            currResult = 0;
        }
        
        return result;
    }
};
