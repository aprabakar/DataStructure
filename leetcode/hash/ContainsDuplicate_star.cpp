// Sliding window
// leet -> https://leetcode.com/problems/contains-duplicate-ii/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;
        int pos;
        
        for(pos = 0; pos < nums.size() && pos <= k ; pos++){
            if(set.count(nums[pos])){
                return true;
            }
            set.insert(nums[pos]);
        }
        
        for(int i = pos ; i < nums.size() ; i++){
            int deleteIndex = i-k-1;
            set.erase(nums[deleteIndex]);

            if(set.count(nums[i])){
                return true;
            }
            set.insert(nums[i]);
        }
        
        return false;
    }
};
