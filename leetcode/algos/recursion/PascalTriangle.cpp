class Solution {
    
public:    
    
    vector<vector<int>> dp{34,vector<int>(34 , 0)};
    int findVal(int row, int col){
        if(row == 0 || col == 0 || row == col){
            return 1;
        }
        
        if(dp[row][col]){
            return dp[row][col];
        }
        
        dp[row][col] = findVal(row-1,col-1) + findVal(row-1,col);
        return dp[row][col];
    }
    
    
    vector<int> getRow(int rowIndex) {
        
        vector<int> pascalTriangle;
        for(int i = 0 ; i<= rowIndex ; i++){
           if(i == 0 || i == rowIndex){
               pascalTriangle.push_back(1);
           }else{
               pascalTriangle.push_back(findVal(rowIndex,i));
           }
        }
        
        return pascalTriangle;
    }
};
