class Solution {
public:
    string encode(int i , int j){
        return to_string(i) + "_" + to_string(j);
    }
    
    vector<int> decode(string s){
        vector<int> pos(2);
        string delimiter = "_";
        string prefix_i = s.substr(0, s.find(delimiter));
        string prefix_j = s.substr(s.find(delimiter)+1, s.length());
        pos[0] = stoi(prefix_i);
        pos[1] = stoi(prefix_j);
        return pos;
    }
    
    bool isValid(string pos, vector<vector<char>>& grid){
        int i,j;
        vector<int> posList = decode(pos);
        i = posList[0];
        j = posList[1];
        
        if(grid[i][j] == '1'){
            return true;
        }
        return false;
    }    
    
    int numIslands(vector<vector<char>>& grid) {
        int noOfIslands = 0;
        map<string,int> visitedMap;
        
        int height = grid.size();
        
        // Loop through the grid
        for (int i=0 ;i< grid.size() ; i++){
            for(int j=0 ;  j < grid[i].size(); j++){
                string pos = encode(i,j);
                
                // If the node is 1 and not visited, start BFS
                if(isValid(pos, grid) && visitedMap.find(pos) == visitedMap.end()){
                    
                    //Initialize the Queue and mark as an Island
                    deque<string> bfsQueue;
                    bfsQueue.push_back(pos);
                    noOfIslands += 1;
                    visitedMap[pos] = 1;
                    int width = grid[i].size();
                    
                    //Do the BFS till the queue becomes empty
                    while(!bfsQueue.empty()){
                        
                        string currPos = bfsQueue.front();
                        //cout<<" currPos = "<< currPos << endl;
                        bfsQueue.pop_front();
                        vector<int> currLoc = decode(currPos);
                        int curr_i = currLoc[0];
                        int curr_j = currLoc[1];
                            
                        // Four Path possible at any points horizontal and vertical 
                        // Three checks
                        // 1. Valid position , 2. Contains 1, 3. Not visited before
                        
                        if(curr_j-1 >= 0){
                           string left = encode(curr_i,curr_j-1);
                           if(isValid(left, grid) && visitedMap.find(left) == visitedMap.end()){
                            bfsQueue.push_back(left);
                            visitedMap[left] = 1;
                           }
                        }
                        
                        if(curr_j+1 < width){
                            string right = encode(curr_i,curr_j+1);
                           if(isValid(right, grid) && visitedMap.find(right) == visitedMap.end()){
                              bfsQueue.push_back(right);
                              visitedMap[right] = 1;
                             }
                        }
                        
                        if(curr_i-1 >= 0){
                            string top = encode(curr_i-1,curr_j);
                            if(isValid(top, grid) && visitedMap.find(top) == visitedMap.end()){
                               bfsQueue.push_back(top);
                               visitedMap[top] = 1;
                             }                            
                        }
                        
                        if(curr_i+1 < height){
                            string down = encode(curr_i+1,curr_j);
                            if(isValid(down, grid) && visitedMap.find(down) == visitedMap.end()){
                               bfsQueue.push_back(down);
                               visitedMap[down] = 1;
                            }                                
                        }
                    }
                }
            }
        }
    
        return noOfIslands;
    }
};
