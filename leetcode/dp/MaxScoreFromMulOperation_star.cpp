// leet -> https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/
// Brute force

class Solution {
public:
    
    int final_ans = INT_MIN;
    void maximumScoreUtil(vector<int>& nums , vector<int>& multipliers , 
                         int mulPos, int startPos, int endPos, int currAns){
        
        if(mulPos == multipliers.size()){
            final_ans = max(final_ans,currAns);
            return;
        }  
        
        int firstPosAns = currAns + (multipliers[mulPos] * nums[startPos]);
        int lastPosAns = currAns + (multipliers[mulPos] * nums[endPos]);
        
        maximumScoreUtil(nums,multipliers,mulPos+1,startPos+1,endPos,firstPosAns);                             maximumScoreUtil(nums,multipliers,mulPos+1,startPos,endPos-1,lastPosAns);                       
                                  
        return;
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        maximumScoreUtil(nums,multipliers, 0,0,nums.size()-1, 0);
        return final_ans;
    }
};

//DP Top-down
class Solution {
public:
    vector<vector<int>> dp{1001,vector<int>(1001,INT_MIN)};
    
    int maximumScoreUtil(vector<int>& nums , vector<int>& multipliers ,int mulPos, int left){
        
        if(mulPos == multipliers.size()){
            return 0;
        }
         
        
        int mult = multipliers[mulPos];
        int right = (nums.size() - 1) - (mulPos - left);
        
        int leftPosVal =  mult * nums[left];
        int rightPosVal =  mult * nums[right];
        
        if(dp[left][mulPos] == INT_MIN){
           dp[left][mulPos] = max(leftPosVal + maximumScoreUtil(nums,multipliers,mulPos+1,left+1),
                                  rightPosVal + maximumScoreUtil(nums,multipliers,mulPos+1,left)); 
        }
        
        return dp[left][mulPos];
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        return maximumScoreUtil(nums,multipliers, 0,0);
    }
};
