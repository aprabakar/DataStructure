class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int minNum , countOfNegativeNums = 0;
        
        minNum = INT_MAX;
        for(int i=0 ; i < matrix.size() ; i++){
            for(int j=0 ; j < matrix[i].size() ; j++){
                
                totalSum += abs(matrix[i][j]);
                minNum = min(minNum,abs(matrix[i][j]));
                
                if(matrix[i][j] < 0){
                    countOfNegativeNums += 1;
                }
           }
        }
            
       if(countOfNegativeNums %2 == 0){
           return totalSum;
       }
       
       return totalSum - 2*minNum;
    }
};  
