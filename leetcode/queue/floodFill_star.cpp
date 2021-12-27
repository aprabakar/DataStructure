class Solution {
public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int, int>> bfsQ;
        int colorCode = image[sr][sc];
        
        //base case
        if(newColor == colorCode){
            return image;
        }
        
        bfsQ.push(make_pair(sr,sc));
        
        int height = image.size();
        int width = image[0].size();
        
        while(!bfsQ.empty()){
            pair<int, int> currPos = bfsQ.front();
            bfsQ.pop();
            
            int i = currPos.first;
            int j = currPos.second;
            
            image[i][j] = newColor;
            
            // check four directions
            // Add to the queue if its with same color and not visited before
            // Mark the new color for the valid ones
            
            if(i-1 >= 0 && image[i-1][j] == colorCode){
               bfsQ.push(make_pair(i-1,j));
            }
            if(j-1 >= 0 && image[i][j-1] == colorCode){
               bfsQ.push(make_pair(i,j-1)); 
            }
            if(i+1 < height && image[i+1][j] == colorCode){
               bfsQ.push(make_pair(i+1,j)); 
            }
            if(j+1 < width && image[i][j+1] == colorCode){
               bfsQ.push(make_pair(i,j+1));
            }
        }
        
        return image;
        
    }
};
