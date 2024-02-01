//Adjacent matrix:
//DFS

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

//Djikstra's

  int minScore(int n, vector<vector<int>>& roads) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        vector<int> dist(n+1, INT_MAX);
        vector<vector<pair<int,int>>> graph(n+1);

        for(int i=0; i < roads.size(); i++){
            graph[roads[i][0]].push_back(make_pair(roads[i][1],roads[i][2]));
            graph[roads[i][1]].push_back(make_pair(roads[i][0],roads[i][2]));
        }

        minHeap.push({INT_MAX, 1});

        while(!minHeap.empty()){
            int currWeight = minHeap.top().first;
            int currNode = minHeap.top().second;
            minHeap.pop();

            for(int i=0; i < graph[currNode].size(); i++){
                int weight = min(currWeight, graph[currNode][i].second);

                if(weight < dist[graph[currNode][i].first]){
                    dist[graph[currNode][i].first] = weight;
                    minHeap.push({weight, graph[currNode][i].first});
                }
            }
        }

        return dist[n];
    }

//Bellman ford

   vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        for (int i = 0; i < V - 1; i++) {
                for (auto it : edges) {
                        int u = it[0];
                        int v = it[1];
                        int wt = it[2];
                        if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                                dist[v] = dist[u] + wt;
                        }
                }
        }
        // Nth relaxation to check negative cycle
        for (auto it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                        return { -1};
                }
        }


        return dist;
   }

// prim's algo

    int distance(vector<int>a,vector<int>b){
        return abs(a[1]-b[1]) + abs(a[0]-b[0]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int,int>>adj[points.size()];
        for(int i=0;i<points.size()-1;i++){
            for(int j=i+1;j<points.size();j++){
                int w = (distance(points[i],points[j]));
                adj[i].push_back({w,j});
                adj[j].push_back({w,i});
            }
        }
        map<int,bool>visited;
        for(int i=0;i<points.size();i++){
            visited[i]=false;
        }
        int minpath=0;
        priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(auto x:adj[0]){ 
            pq.push(x);
        }
        visited[0]=true;
        while(!pq.empty()){
            int u=pq.top().second;
            int w=pq.top().first;
            pq.pop();
            if(visited[u]==false){
                minpath+=w;
                visited[u]=true;
                for(auto x:adj[u]){
                    if(visited[x.second]==false){
                        pq.push(x);
                    }
                }
            }
        }
        return minpath;
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
https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/description/
https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
https://leetcode.com/problems/number-of-closed-islands/description/
https://leetcode.com/problems/number-of-enclaves/description/
https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/
https://leetcode.com/problems/is-graph-bipartite/description/
https://leetcode.com/problems/detonate-the-maximum-bombs/description/
https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/
https://leetcode.com/problems/path-with-minimum-effort/description/
https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
https://leetcode.com/problems/number-of-provinces/description/
https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
https://leetcode.com/problems/min-cost-to-connect-all-points/
https://leetcode.com/problems/network-delay-time/
https://leetcode.com/problems/path-with-maximum-probability/description/
https://leetcode.com/problems/reconstruct-itinerary/description/
https://leetcode.com/problems/swim-in-rising-water/description/
