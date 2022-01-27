// leet -> https://leetcode.com/problems/split-array-largest-sum/submissions/
// YT -> https://www.youtube.com/watch?v=nYjriZ-nBtw

class Solution {
public:
    
    bool ok(int mid , vector<int>& nums , int m){
        int total=0;
        int sub_array=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>mid)
                return false;
            if(total+nums[i]<=mid)
                total+=nums[i];
            else{
                sub_array++;
                total=nums[i];
            }
        }
        sub_array++;
        return (sub_array<=m);
    }
    
    int splitArray(vector<int>& nums, int m) {
        int total = 0 , maxNum = INT_MIN;
        for(int i = 0 ; i< nums.size() ; i++){
            total += nums[i];
            maxNum = max(maxNum, nums[i]);
        }
        int l=maxNum;
        int r=total;
        while(l<r){
            int mid=(l+r)/2;
            if(ok(mid,nums,m))
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};
