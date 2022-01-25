// leet-> https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/


class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        
       int m = mat.size(), n = mat[0].size();
		vector<int> tmp(k, 5001);
		for(int j =0;j<n && j< k;++j){
			tmp[j] = mat[0][j];
		}
		priority_queue<int> pq;//max_heap
		for (int i = 1; i < m;++i){
			for (int j = 0; j < n && j < k;++j){
				for (int s = 0; s < k;++s){
					int val = tmp[s] + mat[i][j];
					if(pq.size() < k){
						pq.push(val);
					}
					else if(val < pq.top()){
						pq.pop();
						pq.push(val);
					}
				}
			}
			int tmp_j = pq.size();
			while(!pq.empty()){
				tmp[--tmp_j] = pq.top();
				pq.pop();
			}
		}
		return tmp[k-1];
    }
};
