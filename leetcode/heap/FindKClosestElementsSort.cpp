// Heap solution
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> maxHeap;
        vector<int> result;
        
        for(int i=0 ; i< arr.size() ; i++){
            int absDiff = abs(arr[i] - x);
            
            if(maxHeap.size() < k || absDiff <= maxHeap.top().first){
                maxHeap.push({absDiff, arr[i]});
            }
            
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        
        while(!maxHeap.empty()){
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        sort(result.begin(), result.end());
        
        return result;
    }
};

// Binary Search

// case 1: x - A[mid] < A[mid + k] - x, need to move window go left
// -------x----A[mid]-----------------A[mid + k]----------

// case 2: x - A[mid] < A[mid + k] - x, need to move window go left again
// -------A[mid]----x-----------------A[mid + k]----------

// case 3: x - A[mid] > A[mid + k] - x, need to move window go right
// -------A[mid]------------------x---A[mid + k]----------

// case 4: x - A[mid] > A[mid + k] - x, need to move window go right
// -------A[mid]---------------------A[mid + k]----x------

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        while (left < right) {
            int mid = (left + right) / 2;
            if (x - arr[mid] > arr[mid + k] - x)
                left = mid + 1;
            else
                right = mid;
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
