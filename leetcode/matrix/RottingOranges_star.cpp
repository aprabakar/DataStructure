class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int row = grid.size() , col = grid[0].size();
        int final_time = -1 , freshOranges = 0;
        queue<pair<int,int>> bfsQ;
        vector<int> dir = {-1,0,1,0,-1};
        
        for(int i=0 ; i < row ; i++){
            for(int j=0 ; j<col ; j++){
                if(grid[i][j] == 2){
                    bfsQ.push(make_pair(i,j));
                }
                
                if(grid[i][j] == 1){
                    freshOranges++;
                }
                
            }
        }
        
        while(!bfsQ.empty()){
            int size = bfsQ.size();
            
            while(size--){
                pair<int,int> pos = bfsQ.front();
                bfsQ.pop();
                int curr_i = pos.first , curr_j = pos.second;
                for(int i=0 ; i < 4 ; i++){
                    
                    int curr_i = pos.first + dir[i];
                    int curr_j = pos.second + dir[i+1];
                    
                    if(curr_i >= 0 && curr_i < row && curr_j >= 0 && curr_j < col && grid[curr_i][curr_j] == 1){
                        bfsQ.push(make_pair(curr_i,curr_j));
                        grid[curr_i][curr_j] = 2;
                        freshOranges--;
                    }
                    
                }
            }
            
            final_time++;
        }
        
        final_time = (final_time == -1) ? 0 : final_time;
                
        //cout << "final_time = "<< final_time<<" freshOranges= " <<freshOranges<<endl;
        return (!freshOranges) ? final_time : -1;
        
        
    }
};
