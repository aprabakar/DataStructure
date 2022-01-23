class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> relativeRankHeap;
        
        for(int i=0 ;i< score.size(); i++){
            relativeRankHeap.push(make_pair(score[i],i));
        }
        
        vector<string> ans(score.size());
        int rank = 1;
        while(!relativeRankHeap.empty()){
            pair<int,int> relativeRank = relativeRankHeap.top();
            relativeRankHeap.pop();
            int pos = relativeRank.second;
            
            if(rank == 1){
                ans[pos] = "Gold Medal";
            }else if(rank == 2){
                ans[pos] = "Silver Medal";
            }else if(rank == 3){
                ans[pos] = "Bronze Medal";
            }else{
                ans[pos] = to_string(rank);
            }
            
            rank++;
        }
        
        return ans;
    }
};
