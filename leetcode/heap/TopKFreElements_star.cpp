// leet -> https://leetcode.com/problems/top-k-frequent-elements

//My approach
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        unordered_map<int, list<int>> topListMap;
        vector<int> ans;
        int newFreq = 0 , curr_max = INT_MIN;
        
        for(int i = 0 ; i< nums.size() ; i++){ 
            if(!countMap.count(nums[i])){
                countMap[nums[i]] = 1;
                newFreq = 1;
            }else{
                int previousFreq = countMap[nums[i]];
                countMap[nums[i]]++;
                topListMap[previousFreq].erase(
                                          find(topListMap[previousFreq].begin(), 
                                               topListMap[previousFreq].end(), nums[i])
                                          );
                newFreq = previousFreq+1;
            }
            curr_max = max(curr_max , newFreq);
            topListMap[newFreq].push_back(nums[i]);
        }
        
        int currPos = 0;
        while(currPos < k && curr_max > 0){
            if(topListMap.count(curr_max) && !topListMap[curr_max].empty()){
               ans.push_back(topListMap[curr_max].front());
               topListMap[curr_max].pop_front();
               currPos++;
            }else{
               curr_max--;
            }
        }
      return ans;
    }
};

//bucket sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int num : nums)
            ++m[num];
        
        vector<vector<int>> buckets(nums.size() + 1); 
        for (auto p : m)
            buckets[p.second].push_back(p.first);
        
        vector<int> ans;
        for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; --i) {
            for (int num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k)
                    break;
            }
        }
        return ans;
    }
};

//heap
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int num : nums){
            map[num]++;
        }
        
        vector<int> res;
        // pair<first, second>: first is frequency,  second is number
        priority_queue<pair<int,int>> pq; 
        for(auto it = map.begin(); it != map.end(); it++){
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > (int)map.size() - k){
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};
