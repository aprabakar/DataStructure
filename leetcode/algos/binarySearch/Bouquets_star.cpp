// leet -> https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

class Solution {
public:
    bool checkPossiblity(vector<int>& bloomDay , int currDays, int bouquetCount, 
                         int bouquetSize){
        
        // [1,10,3,10,2]
        int countOfContinousDays = 0 , countOfPossibleBouquet = 0;
        for(int i=0 ; i< bloomDay.size() ; i++){
            if(bloomDay[i] <= currDays){
                countOfContinousDays ++;
            }else{
                countOfContinousDays = 0;
            }
            
            if(countOfContinousDays > 0){
                if(countOfContinousDays == bouquetSize){
                    countOfPossibleBouquet ++;
                    countOfContinousDays = 0;
                }
            }
        }
        
        return (countOfPossibleBouquet >= bouquetCount);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        if(m*k > bloomDay.size()){
            return -1;
        }
        
        int left = INT_MAX , right = INT_MIN;
        
        for(int i= 0 ; i< bloomDay.size() ; i++){
            left = min(left, bloomDay[i]);
            right = max(right, bloomDay[i]);
        }
        
        while(left <= right){
            int mid = (left + right) /2;
            
            if(checkPossiblity(bloomDay, mid , m, k)){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        
        return left;
              
    }
};
