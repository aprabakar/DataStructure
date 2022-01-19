// leet -> https://leetcode.com/explore/learn/card/heap/646/practices/4016/

class KthLargest {
public:
    priority_queue<int,vector<int>, greater<int>> minHeap;
    int kVal;
    KthLargest(int k, vector<int>& nums) {
        kVal = k;
        for(int i = 0 ; i< nums.size(); i++){
            if(minHeap.size() == k && nums[i] >= minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[i]);
            }else if(minHeap.size() < k){
                minHeap.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(minHeap.size() < kVal){
             minHeap.push(val);
        }else if(val >= minHeap.top()){
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
};
