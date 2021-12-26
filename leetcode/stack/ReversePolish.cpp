class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st_exp;
        
        for(int i= 0 ; i< tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int secondNo = stoi(st_exp.top());
                st_exp.pop();
                int firstNo =  stoi(st_exp.top());
                st_exp.pop();
                int result;
                string exp = tokens[i];
                if(exp == "+"){
                    result =  firstNo + secondNo;
                }else if(exp == "-"){
                    result =  firstNo - secondNo;
                }else if(exp == "*"){
                    result =  firstNo * secondNo;
                }else{
                    result =  firstNo / secondNo;
                }
                st_exp.push(to_string(result));
            }else{
                st_exp.push(tokens[i]);
            }
        }
        
        return stoi(st_exp.top());
        
    }
};
