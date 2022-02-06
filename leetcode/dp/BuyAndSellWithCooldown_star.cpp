// leet ->

class Solution {
public:
    
    // Recursive Soltion
    // Time : O(2^N)
    // Space : O(N)
    
//     int solveRec(vector<int>& prices, int day, bool buy){
        
//         if(day >= prices.size()){
//             return 0;
//         }
        
//         // First Choice
//         int ans1 = solveRec(prices, day + 1, buy); // no transaction this day
        
        
//         // Second Choice
//         int ans2 = 0;
//         // doing the required transaction this day
//         if(buy){
//             ans2 = -prices[day] + solveRec(prices, day + 1, false);
//         }else{
//             ans2 = prices[day] + solveRec(prices, day + 2, true);
//         }
        
//         return max(ans1, ans2);
        
//     }
    
    
    // Memoization Soltion
    // Time : O(N)
    // Space : O(N)
   
//     int solveMemo(vector<int>& prices, int day, bool buy, vector<vector<int>> &memo){
        
//         if(day >= prices.size()){
//             return 0;
//         }
        
//         int &ans = memo[day][buy];
        
//         if(ans != -1){
//             return ans;
//         }
        
//         // First Choice
//         int ans1 = solveMemo(prices, day + 1, buy, memo); // no transaction this day
        
        
//         // Second Choice
//         int ans2 = 0;
//         // doing the required transaction this day
//         if(buy){
//             ans2 = -prices[day] + solveMemo(prices, day + 1, false, memo);
//         }else{
//             ans2 = prices[day] + solveMemo(prices, day + 2, true, memo);
//         }
        
//         return ans = max(ans1, ans2);
        
//     }
    
    
    // Dynamic Programming Solution 
    // Time : O(N)
    // Space : O(N)
    
    int solveDP1(vector<int> &prices){ 
        
         int dp[prices.size() + 2][2];
        

        for(int day = (int)prices.size() + 1;day >= 0;day--){
            for(int buy = 0;buy <= 1;buy++){
                
    
                int &ans = dp[day][buy];
                
                if(day >= prices.size()){
                    ans = 0;
                }else{
                    
                    // First Choice
                    int ans1 = dp[day + 1][buy]; // no transaction this say
                
                    
                    // Second Choice
                    int ans2 = 0; // doing the required transaction this day
                    
                    if(buy){
                        ans2 = -prices[day] + dp[day + 1][0];
                    }else{
                        ans2 = prices[day] + dp[day + 2][1];
                    }
                    
                    ans = max(ans1, ans2);
                    
                }
            }
        }
        
        return dp[0][1];
        
        
    }
    
    // Dynamic Programming Solution 
    // Time : O(N)
    // Space : O(1)
    
//      int solveDP2(vector<int> &prices){ 
        
//          int dp[3][2];
        
//         for(int i = 0;i <= 2;i++){
//                 for(int j = 0;j <= 1;j++){
//                     dp[i][j] = 0;
//                 }
//         }
        
//         for(int day = (int)prices.size() - 1;day >= 0;day--){
//             for(int buy = 0;buy <= 1;buy++){
                
    
//                 int &ans = dp[day % 3][buy];
                
                    
//                 // First Choice
//                 int ans1 = dp[(day + 1) % 3][buy]; // no transaction this say
                
                    
//                 // Second Choice
//                 int ans2 = 0; // doing the required transaction this day
                    
//                 if(buy){
//                     ans2 = -prices[day] + dp[(day + 1) % 3][0];
//                 }else{
//                     ans2 = prices[day] + dp[(day + 2) % 3][1];
//                 }
                    
//                 ans = max(ans1, ans2);
                    
//             }
//         }
        
//         return dp[0][1];
        
        
//     }
    
    
    int maxProfit(vector<int>& prices) {
        
       int ans = 0; 
        
       // Recursive Solution 
       // ans = solveRec(prices, 0, true);
        
       // Memoization Solution
        //vector<vector<int>> memo(prices.size() + 2, vector<int>(2, -1));
        //ans = solveMemo(prices, 0, true, memo);
       
        // DP solution with O(N) space
       ans = solveDP1(prices);
        
       // DP solution with O(1) space
       //ans = solveDP2(prices); 
       
        
        return ans;
        
    }
};
