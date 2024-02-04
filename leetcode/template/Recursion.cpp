//Basic functional
int fib(int n) {
    if(n == 0){
        return 0;
    }

    if(n == 1){
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

// take and don't take
vector<int> ans;
void solve(vector<int> arr, int index, int sum){
    if(index == arr.size()){
        ans.push_back(sum);
        return;
    }
    
    solve(arr, index+1, arr[index] + sum); // take
    solve(arr, index+1, sum); // don't take
}
vector<int> subsetSums(vector<int> arr, int N){
    solve(arr, 0, 0);
    return ans;
}

//eliminate duplicates
//https://leetcode.com/problems/subsets-ii/submissions/1165653292/
set<vector<int>> ans;
void solve(vector<int> nums, int index, vector<int> v){
    if(index == nums.size()){
        ans.insert(v);
        return;
    }
    
    v.push_back(nums[index]);
    solve(nums, index+1, v); // take
    v.pop_back();
    solve(nums, index+1, v); // don't take
}    
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    solve(nums, 0, {});
    vector<vector<int>> result(ans.begin(), ans.end());
    return result;        
}


//Problems:
https://leetcode.com/problems/subsets-ii/submissions/1165653292/
