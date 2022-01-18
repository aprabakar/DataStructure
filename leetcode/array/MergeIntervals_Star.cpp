//leet - https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    // Compares two intervals
    // according to starting times.
    bool static compareInterval(const vector<int>& v1, const vector<int>& v2){
            return v1[0] < v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(),compareInterval);
        
        vector<vector<int>> result;
        int startPoint = intervals[0][0];
        int endPoint = INT_MIN;
        // [1,7] [1,6], [8,10] [8,7]
        for(int i = 0 ; i < intervals.size() ; i++){
            endPoint = max (endPoint , intervals[i][1]);
            if(i+1 == intervals.size() || endPoint < intervals[i+1][0]){
                vector<int> curr_result;
                curr_result.push_back(startPoint);
                curr_result.push_back(endPoint);
                endPoint = INT_MIN;
                result.push_back(curr_result);
                if(i+1 != intervals.size()){
                   startPoint = intervals[i+1][0]; 
                }  
            }
        }
        
        return result;
    }
};
