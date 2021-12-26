class Solution {
public:
    // DP with DFS
    map<string, int> dpMap;
    int dfs(vector<int>& nums, int currVal, int pos , int target){
        if(pos == nums.size()){
            return (currVal == target) ? 1 : 0;
        }
        
        string key = to_string(pos) + "_" + to_string(currVal);
        if(dpMap.find(key) != dpMap.end()){
            return dpMap[key];
        }
        
        //           (0,0)
        //       (1,1)    (-1,1)
        //  (3,2) (-1,2) (-3,2) (1,2)
        
        int res = dfs(nums,currVal+nums[pos], pos+1,target) +
                  dfs(nums,currVal-nums[pos], pos+1,target);
        dpMap[key] = res;
        return dpMap[key];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums,0,0,target);
    }
};
