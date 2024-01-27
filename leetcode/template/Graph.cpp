//Adjacent matrix:

bool isNotValid(int i, int j, int m, int n){
        return (i <0 || j<0 || i>=m || j>=n);
    }

    void dfs(vector<vector<char>>& grid, int row, int col, vector<vector<int>>& visited){
        visited[row][col] = 1;
        vector<vector<int>> dir = {{0,-1}, {-1,0}, {0,1}, {1,0}};

        for(int i=0; i < dir.size(); i++){
            int new_row = row+dir[i][0], new_col = col+dir[i][1];

            if(!isNotValid(new_row, new_col, grid.size(), grid[0].size()) &&
                !visited[new_row][new_col] && grid[new_row][new_col] == '1'){
                dfs(grid, new_row, new_col, visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int ans = 0;
        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[i].size(); j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    visited[i][j] = 1;
                    dfs(grid, i, j, visited);
                    ++ans;
                }
            }
        }

        return ans;
    }





//Problems:
https://leetcode.com/problems/pacific-atlantic-water-flow
https://leetcode.com/problems/surrounded-regions/description/
https://leetcode.com/problems/rotting-oranges
