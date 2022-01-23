// leet -> https://leetcode.com/explore/learn/card/heap/646/practices/4091/

class Solution {
public:
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> minJumpLengthHeap;
        int sumOfRemainingJumps = 0;
        
        // Ladder for Top L jumps which is <= ladders count
        // Bricks for All the remaining total sum of Jumps which is <= Bricks
    
        for(int i= 0 ; i< heights.size()-1; i++){
            if(heights[i+1] > heights[i]){
                int currJumpLen = heights[i+1] - heights[i];
                minJumpLengthHeap.push(currJumpLen);
                if(minJumpLengthHeap.size() > ladders){
                    sumOfRemainingJumps += minJumpLengthHeap.top();
                    minJumpLengthHeap.pop(); 
                }
            }
           if(sumOfRemainingJumps > bricks){
               return i;
           } 
        }
        
        return heights.size()-1;
    }
};
