class Solution {
public:
    unordered_map<char,string> charMap =  {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    
    vector<string> result;
    
    void solve(string digits, int index, string combination){
        if(index == digits.size()){
            result.push_back(combination);
            return;
        }
        
        string currNumPad = charMap[digits[index]];
        
        for(int i =0 ; i< currNumPad.size() ; i++){
            string currCombination = combination + currNumPad[i];
            solve(digits,index+1,currCombination);
        }
        
        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return result;
        }
        solve(digits,0, "");
        return result;
    }
};

// Iterative
class Solution {
public:
    const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
		vector<string> result;
        result.push_back("");
        
        for(auto digit: digits) {
            vector<string> tmp;
            for(auto candidate: pad[digit - '0']) {
                for(auto s: result) {
                    tmp.push_back(s + candidate);
                }
            }
            result.swap(tmp);
        }
        return result;
    }
};
