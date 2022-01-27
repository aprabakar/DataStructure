// leet -> https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
     bool checkPossiblity(vector<int>& piles , int currSpeed, int totalHours){
        
        // [1,10,3,10,2]
        int hoursTakeForThisSpeed = 0;
        for(int i=0 ; i< piles.size() ; i++){
            if(piles[i] <= currSpeed){
                hoursTakeForThisSpeed += 1;
            }else{
                if(piles[i] % currSpeed == 0){
                    hoursTakeForThisSpeed += (piles[i]/currSpeed);
                }else{
                    hoursTakeForThisSpeed += (piles[i]/currSpeed) + 1;
                }
            }
        }
        
        return (hoursTakeForThisSpeed <= totalHours);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int left = 1 , right = INT_MIN;
        
        for(auto &p : piles) {
            if(p > right)
                right = p;
        }        
        
        while(left <= right){
            int mid = (left + right) /2;
            
            if(checkPossiblity(piles, mid ,h)){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        
        return left;
    }
};
