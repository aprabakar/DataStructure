// leet -> https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/submissions/

class Solution {
public:
    
    bool checkPosibility(vector<int>& weights , int capacity , int days){
        int countOfDays = 0 , currCapacity = 0;
        
        // 3,2,2,4,1,4
        // 1        16
        // 1    7  
        //   5  7
        //   5 5
        for(int i = 0 ; i< weights.size() ; i++){
            if(weights[i] > capacity){
                return false;
            }
            
            if(weights[i] + currCapacity > capacity){
                countOfDays +=1;
                currCapacity = weights[i];
            }else{
                currCapacity += weights[i];
            }
        }
        countOfDays += 1;
        return (countOfDays <= days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = INT_MIN , right = 0, mid;
        
        for (int i = 0 ; i< weights.size() ; i++){
            right += weights[i];
            left = max(left, weights[i]);
        }
        
        while(left <= right){
            mid = (left + right) / 2;
            
            if(checkPosibility(weights,mid,days)){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        
        return left;
    }
};
