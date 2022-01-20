class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> maxHeap;
        
        for(int i=0; i< matrix.size() ; i++){
            for(int j=0; j< matrix[i].size() ; j++){
                if(maxHeap.size()  < k){
                    maxHeap.push(matrix[i][j]);
                }else if(matrix[i][j] < maxHeap.top()){
                    maxHeap.pop();
                    maxHeap.push(matrix[i][j]);
                }
            }
        }
        return maxHeap.top();
    }
};
