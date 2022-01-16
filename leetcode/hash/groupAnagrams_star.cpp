// leet - https://leetcode.com/problems/group-anagrams/
class Solution {
public:
    string strSort(string s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }  
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> result;
        
        for(int i = 0 ; i< strs.size() ; i++){
            string unSortedString = strs[i];
            string sortedString = strSort(unSortedString);
            map[sortedString].push_back(unSortedString);
        }
        
        for (auto mapVal : map){
            result.push_back(mapVal.second);
        }
        
        return result;
        
    }
};
