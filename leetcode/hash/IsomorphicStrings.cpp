class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //base case
        if(s.length()  != t.length())
            return false;
        
        unordered_map<char,char> direct_map;
        unordered_map<char,char> reverse_map;
        
        for(int i =0 ; i< s.length(); i++){
            auto d_search = direct_map.find(s[i]);
            
            if(d_search != direct_map.end()){
                if(t[i] != d_search->second){
                    return false;
                }
            }else{
                direct_map[s[i]] = t[i];
            }
            
            auto r_search = reverse_map.find(t[i]);
            
            if(r_search != reverse_map.end()){
                if(s[i] != r_search->second){
                    return false;
                }
            }else{
                reverse_map[t[i]] = s[i];
            }
            
        }
        
        return true;
    }
};
