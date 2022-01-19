// Heap function over vector
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        
        for(int i= 0 ; i < k-1 ; i++){
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        
        return nums.front();
    }
};

// Priority queue implementation
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector<int>> maxHeap;
        
        for(int i=0;i<nums.size();i++)
            maxHeap.push(nums[i]);
        
        for(int i=1;i<k;i++)
            maxHeap.pop();
        
        return maxHeap.top();        
    }
};


// Priority queue another implementation
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(int i=0;i<nums.size();i++){
            
            if(minHeap.size() == k && nums[i] >= minHeap.top()){
                minHeap.pop();
                minHeap.push(nums[i]);
            }else if(minHeap.size() < k){
                minHeap.push(nums[i]);
            }
        }
        
        return minHeap.top();        
    }
};

