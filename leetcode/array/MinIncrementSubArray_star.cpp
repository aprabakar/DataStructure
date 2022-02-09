// small code for the hard question ever solved
// leet -> https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res = target[0];
         // this question needs nothing but some imagination...
        // imagine we are building some building/pyramid off ground 
        // as only "subarray" could be incremented, we need to do work 
        // (here the "count") to bring them up
        // one by one (one level by one level)
        for (int i = 1; i < target.size(); ++i){
            // if there are a increasing subarry
            // accumuate these diffs as they are levels we need to build
            // if go down, we no need to care because I already build it up right
            // but if rise up again which means another building 
            // so accumulate it again
            res += max(target[i] - target[i - 1], 0); 
            cout<<" ele= "<<target[i]<<" res = "<<res<<endl;
        }
            
        return res;
    }
};
