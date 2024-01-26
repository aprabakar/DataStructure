class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz), count(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    // find by path compression (logn)
    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    // union by rank (logn)
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
            count--;
        }
    }

    int getCount() {
        return count;
    }

private:
    vector<int> root;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.size() == 0) {
            return 0;
        }
        int n = isConnected.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    uf.unionSet(i, j);
                }
            }
        }
        return uf.getCount();
    }
};






// Good example:
https://leetcode.com/problems/smallest-string-with-swaps/

  int find(int i, vector<int>& parent){
      if(parent[i]==-1 || parent[i]==i){
          return parent[i] = i;
      }
      return parent[i] = find(parent[i],parent);
  }
  
  void unionn(int i, int j, vector<int>& parent, vector<int>& rank){
      int x = find(i,parent);
      int y = find(j,parent);
      if(x == y) return;
      if(rank[x] > rank[y]){
          parent[y] = x; 
      }else if(rank[x] < rank[y]){
          parent[x] = y;
      }else{
          parent[x] = y;
          rank[y]++;
      }
  }
  
  string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
      int n = s.size();
      vector<int> parent(n,-1);
      vector<int> rank(n,1);
      for(auto it:pairs){
          int u = it[0];
          int v = it[1];
          unionn(u,v,parent,rank);
      }
      for(int i=0; i<n; i++){
          find(i,parent);
      }

      unordered_map<int,vector<int>> mp;
      for(int i=0; i<n; i++){
          mp[parent[i]].push_back(i);
      }
      string res = s;
      for(auto it:mp){
          vector<int> v = it.second;
          vector<char> ds;
          for(auto x:v){
              ds.push_back(s[x]);
          }
          sort(ds.begin(),ds.end());
          for(int i=0; i<v.size(); i++){
              res[v[i]] = ds[i];
          }
      }
      return res;
  }
