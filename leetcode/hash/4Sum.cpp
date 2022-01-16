class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans = 0;
        unordered_map<int, int> map;
        int length = nums4.size();
        
        for(int i = 0 ;i < length ; i++){
            for(int j= 0 ; j < length;  j++){
                int secondHalfSum = nums3[i]+ nums4[j];
                map[secondHalfSum]++;
            }
        }
        
        for(int i = 0 ;i < length ; i++){
            for(int j = 0 ;j < length ; j++){
                int firstHalfSum = nums1[i] + nums2[j];
                int remainSum = 0-firstHalfSum;
                if(map.count(remainSum)){
                    ans += map[remainSum];
                }
           }
      }
        
      return ans;  
    }
};
