class Solution {
public:
    string nTimesString(string s, int n){
        string ans = "";
        for (int i = 0; i < n; i++) ans += s;
        return ans;
    }
    string decodeString(string s) {
        stack<string> st;
        string currStr = "";
        string currNum = "";
        for (auto &c : s) {
            
            if(c == '['){
                st.push(currStr);
                st.push(currNum);
                currStr = currNum = "";
            }else if(c == ']'){
                currNum = st.top(); st.pop();
                string prev = st.top(); st.pop();
                currStr = prev + nTimesString(currStr, stoi(currNum));
                currNum = "";
            }else if(isdigit(c)){
                currNum += c;
            }else{
                currStr += c;
            }
        }
        
        // 1 -> ""
        // a -> "a"
        // a1[b] -> "ab"
        // Not valid inputs (1[], a[] , a[1] , 1[1])  
        return currStr;
    }
};
