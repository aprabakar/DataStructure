class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int firstPrev = cost[0] , secondPrev , ans;
        secondPrev = cost[1];
         for(int i = 2 ; i < cost.size() ; i++){
            int temp = cost[i] + min(firstPrev, secondPrev);
            firstPrev = secondPrev;
            secondPrev = temp;
        }
        
        return min(firstPrev,secondPrev);
    }
};

// 1,100,1,1,1,100,1,1,100,1
// 1,100,2,2,
