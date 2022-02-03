// leet -> https://leetcode.com/problems/maximal-square/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> result(matrix.size(),vector<int>(matrix[0].size(), 0));
        int ans = 0;
        for(int i =0 ;i<matrix.size() ; i++){
            ans = max(ans, matrix[i][0]-'0');
            result[i][0] = matrix[i][0]-'0';
        }
        
        for(int i =0 ;i<matrix[0].size() ; i++){
            ans = max(ans, matrix[0][i]-'0');
            result[0][i] = matrix[0][i]-'0';
        }
        
        for(int i = 1 ; i< matrix.size() ;i++){
            for(int j = 1; j < matrix[i].size();j++){
                if(matrix[i][j] == '1'){
                    result[i][j] = 1 + (min(result[i-1][j-1],min(result[i-1][j],
                                                                 result[i][j-1])));
                }
                ans = max(ans, result[i][j]);
            }
        }
        
        return ans * ans;
    }
};
