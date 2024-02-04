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

// over an array
//https://leetcode.com/problems/palindrome-partitioning/description/
 void solve(string s, int index, vector<string> v){
    if(index == s.length()){
        if(isPalindrome(v)){
            ans.push_back(v);
        }
        return;
    }


    for (int i = index; i < s.length(); i++) {
        v.push_back(s.substr(index, i - index + 1));
        solve(s, i + 1, v);
        v.pop_back();
    }
}
vector<vector<string>> partition(string s) {
    solve(s, 0, {});
    return ans;
}

//permutation
https://leetcode.com/problems/permutations/
void backtrack(int index, vector<int>& nums, vector<int>& list){
    if(index == nums.size()){
        ans.push_back(list);
        return;
    }

    for(int i=index; i < nums.size(); i++){
        int temp = nums[i];
        nums[i] = nums[index];
        nums[index] = temp;

        list.push_back(nums[index]);
        backtrack(index+1, nums, list);
        list.pop_back();

        temp = nums[i];
        nums[i] = nums[index];
        nums[index] = temp;            
    }

    return;
}


//Problems:
https://leetcode.com/problems/subsets-ii/submissions/1165653292/
https://leetcode.com/problems/combination-sum/description/
https://leetcode.com/problems/combination-sum-ii/description/
https://leetcode.com/problems/palindrome-partitioning/description/
https://leetcode.com/problems/permutations/
