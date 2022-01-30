class Solution {
public:
    vector<vector<int>> ans;
    void solve(int n , int start, int k, vector<int> subAns){
        if(k == 0){
           ans.push_back(subAns); 
           return;
        }
        
        for(int i=start ; i<=n ; i++){
            subAns.push_back(i);
            solve(n,i+1,k-1,subAns);
            subAns.pop_back();
            //subAns.erase(find(subAns.begin(),subAns.end(),i));
        }
        
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> subAns;
        solve(n,1,k,subAns);
        return ans;
    }
};
