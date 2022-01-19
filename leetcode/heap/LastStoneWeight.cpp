class Solution {
public:
    
    void heapify(priority_queue<int>& maxHeap){
        int top_ele = maxHeap.top();
        maxHeap.pop();
        int second_top_ele = maxHeap.top();
        maxHeap.pop();

        if(second_top_ele == top_ele){
            maxHeap.push(0);
        }else{
            maxHeap.push(top_ele- second_top_ele);
        }
        
        return;
    }
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1){
            return stones[0];
        }
        
        priority_queue<int> maxHeap;
        
        for(int i=0 ; i< stones.size() ; i++){
            maxHeap.push(stones[i]);            
        }
        
        while(maxHeap.size() > 1){
            heapify(maxHeap);
        }
        
        return maxHeap.top();
    }
};
