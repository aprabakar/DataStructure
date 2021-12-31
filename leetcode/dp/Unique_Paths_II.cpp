//Brute Force -> DFS
class Solution {
public:
    int count = 0;
    int run_count = 0;
    void dfs(vector<vector<int>>& obstacleGrid , int row, int col){
        
        run_count +=1;
        //Base case
        if(row >= obstacleGrid.size() || col >= obstacleGrid[0].size() ||
           obstacleGrid[row][col] == 1){
            return;
        }
        
        //Reached the destination
        if(row == obstacleGrid.size()-1 && col == obstacleGrid[0].size()-1){
            count += 1;
        }
        
        //down
        dfs(obstacleGrid , row+1, col);
        //right    
        dfs(obstacleGrid , row, col+1);
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Brute force
        // Do BFS From the starting Node
        // stop BFS on that path whenever you find obstacle Node.
        // When you reach the destination , increment the count.
        // Don't mark the visited node, bcoz we need to cover all the path
        dfs(obstacleGrid, 0, 0);
        cout << "run_count = "<<run_count<<endl;
        return count;
        
    }
};


//Bottom up Approach -> DP

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int row = obstacleGrid.size() , col = obstacleGrid[0].size();
        long right , down;
        
        for(int i= row -1 ; i >= 0 ; i--){
            for(int j = col-1 ; j >= 0 ; j--){
                
                //Base case
                if(i == row-1 && j == col-1){
                    obstacleGrid[row-1][col-1] = (obstacleGrid[row-1][col-1] == 0) ? 1 : 0;
                    continue;
                }
                
                if(obstacleGrid[i][j] == 0){
                    right = ( j+1 < col) ? obstacleGrid[i][j+1] : 0;
                    down  = ( i+1 < row) ? obstacleGrid[i+1][j] : 0;
                    obstacleGrid[i][j] = right +down;
                }else{
                    obstacleGrid[i][j] = 0;
                }
                
            }
        }
    
        return obstacleGrid[0][0];
    }
};

// Top Down Approach -> DP

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int row = obstacleGrid.size() , col = obstacleGrid[0].size();
        
        //Edge case case
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        
        obstacleGrid[0][0] = 1;
        
        for(int i = 1 ; i < row ; i++){
            obstacleGrid[i][0] =  (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1) ? 1 : 0;
        }        
        
        for(int i = 1 ; i < col ; i++){
            obstacleGrid[0][i] =  (obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1] == 1) ? 1 : 0;
        }
        
        for(int i= 1 ; i < row ; i++){
            for(int j = 1 ; j < col ; j++){
                if(obstacleGrid[i][j] == 0){
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                }else{
                    obstacleGrid[i][j] = 0;
                }
            }
        }
    
        return obstacleGrid[row-1][col-1];
    }
};
