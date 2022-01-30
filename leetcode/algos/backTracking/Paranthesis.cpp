class Solution {
public:
    vector<string>result;
    
    void helper(int open,int close,int n,string current)
    {
        //cout<<" str = "<<current<<endl;
        if(current.length()==n*2)
        {
            cout<<" result = "<<current<<endl;
            result.push_back(current);
            return;
        }
        if(open<n)  helper(open+1,close,n,current+"(");
        if(close<open)  helper(open,close+1,n,current+")");
        //cout<<" str = "<<current<<endl;
    }
    vector<string> generateParenthesis(int n) {
        helper(0,0,n,"");
        return result;
    }
};
