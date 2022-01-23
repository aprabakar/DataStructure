//leet -> https://leetcode.com/problems/reduce-array-size-to-the-half/

// Map + Heap
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> freqMap;
        priority_queue<int> maxHeap;
        int total_size = arr.size();
        int currSize = 0;
        int countOfEle = 0;
        
        for(int i=0 ; i< total_size ; i++){
            freqMap[arr[i]]++;
        }
        
        for (auto pair : freqMap){
            maxHeap.push(pair.second);
        }
        
        
        while(!maxHeap.empty()){
            currSize += maxHeap.top();
            maxHeap.pop();
            countOfEle++;
            
            if((currSize*2) >= total_size){
                break;
            }
        }
        
        return countOfEle;
    }
};


// Map + counting sort

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> cnt;
        for (int x : arr) ++cnt[x];

        vector<int> counting(n + 1);
        for (auto [_, freq] : cnt) ++counting[freq];

        int ans = 0, removed = 0, half = n / 2, freq = n;
        while (removed < half) {
            ans += 1;
            while (counting[freq] == 0) --freq;
            removed += freq;
            --counting[freq];
        }
        return ans;
    }
};
