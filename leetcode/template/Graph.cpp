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


    bool dfs(unordered_map<int, vector<int>> adjList,int currNode, vector<int> visited){
        visited[currNode] = 1;

        for(auto node : adjList[currNode]){
            if(visited[node] == 1){
                return false;
            }
            
            if(visited[node] == 0){
                if(!dfs(adjList, node, visited)){
                    return false;
                }
            }
        }

        visited[currNode] = 2;
        return true;
    }

// Adjacency list

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
int m = prerequisites.size();
unordered_map<int, vector<int>> adjList;
vector<int> visited(numCourses, 0);

if(prerequisites.size() == 0){
    return true;
}

for(int i=0; i < m ; i++) {
    vector<int> list;
    if(adjList.find(prerequisites[i][0]) == adjList.end()){
        list.push_back(prerequisites[i][1]);
    }else{
        list = adjList[prerequisites[i][0]];
        list.push_back(prerequisites[i][1]);
    }

    adjList[prerequisites[i][0]] = list;
}

for(int i=0; i < numCourses ; i++){
    for(auto node : adjList[i]){ 
        if(visited[node] == 0){
            if(!dfs(adjList, node, visited)){
                return false;
            }
        }
    }            
}        

return true;        
}


// BFS and Topological sorting

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
// Kahn's algo / topological sort
vector<int> inDegree(numCourses, 0);
vector<int> ans;
queue<int> q;
unordered_map<int, vector<int>> adjList;

for(int i=0; i < prerequisites.size(); i++){
    vector<int> list;
    if(adjList.find(prerequisites[i][1]) == adjList.end()){
        list.push_back(prerequisites[i][0]);
    }else{
        list = adjList[prerequisites[i][1]];
        list.push_back(prerequisites[i][0]);
    }   
    adjList[prerequisites[i][1]] = list; 
    inDegree[prerequisites[i][0]] += 1;      
}

for(int i=0 ; i < numCourses; i++){
    if(inDegree[i] == 0){
        q.push(i);
    }
}

while(!q.empty()){
    int node = q.front();
    q.pop();
    ans.push_back(node);

    for(auto it : adjList[node]){
        --inDegree[it];
        if(inDegree[it] == 0){
            q.push(it);
        }
    }
}

if(ans.size() == numCourses){
    return ans;
}

return {};
}




//Problems:
https://leetcode.com/problems/pacific-atlantic-water-flow
https://leetcode.com/problems/surrounded-regions/description/
https://leetcode.com/problems/rotting-oranges
https://leetcode.com/problems/course-schedule/
https://leetcode.com/problems/find-eventual-safe-states/
https://leetcode.com/problems/course-schedule-ii
https://leetcode.com/problems/alien-dictionary
https://leetcode.com/discuss/interview-question/4276157/Shortest-path-in-Directed-Acyclic-Graph/
https://leetcode.com/problems/word-ladder
https://leetcode.com/problems/word-ladder-ii/
https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
