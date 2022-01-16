//HashSet
class Solution {
public:
    
    int singleNumber(vector<int>& nums) {
        unordered_set<int> result;
        for(int i = 0; i < nums.size(); i++){
            if(result.count(nums[i]) > 0){
                result.erase(nums[i]);
            }else{
                result.insert(nums[i]);
            }
        }
        return *result.begin();
    }
};

// XOR
class Solution {
public:
    
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i<nums.size(); i++){
            result ^=nums[i];
        }
        return result;
    }
};
