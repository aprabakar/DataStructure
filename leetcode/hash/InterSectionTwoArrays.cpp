class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set;
        unordered_set<int> result;
        for(int i=0 ;i < nums1.size(); i++){
            set.insert(nums1[i]);
        }
        
        for(int i=0 ;i < nums2.size(); i++){
            if(set.count(nums2[i]) > 0){
                result.insert(nums2[i]);
            }
        }
        
        return vector<int>(result.begin() , result.end());
    }
};
