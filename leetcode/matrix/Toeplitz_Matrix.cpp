//My Approach
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int right , down;
        right = down = 0;
        int startVal;
        int i,j;
        while(right < matrix[0].size() || down < matrix.size()){
            i =0;
            if(right < matrix[0].size()){
                j = right;
                startVal = matrix[i][j];
                while(i < matrix.size() && j< matrix[i].size()){
                    if(matrix[i][j] != startVal){
                        return false;
                    }
                    i++;
                    j++;
                }
            }
            
            j = 0;
            if(down < matrix.size()){
                i = down;
                startVal = matrix[i][j];
                while(i < matrix.size() && j< matrix[i].size()){
                    if(matrix[i][j] != startVal){
                        return false;
                    }
                    i++;
                    j++;
                } 
            }
            right++;
            down++;
        }
        
     return true;
    }
};

// Great Approach
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
  int m = matrix.size(), n = matrix[0].size();
  for (int i = 1; i < m; i++)
      for (int j = 1; j < n; j++)
          if (matrix[i][j] != matrix[i - 1][j - 1])
              return false;
  return true;
    }
};
