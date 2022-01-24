// leet -> https://leetcode.com/problems/top-k-frequent-words/

// O(nlogn) Approach MaxHeap
bool myCmp(pair<string,int> p1, pair<string,int> p2)
{
    if(p1.second != p2.second){
        return p1.second > p2.second;
    }
  
    int i = 0;      
    while(i < p1.first.size() && i < p2.first.size()){
        if(p1.first[i] != p2.first[i]){
            return p1.first[i] < p2.first[i];
        }
        
        i++;
    }
    
    return p1.first.size() < p2.first.size();
}    
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freqMap;
        priority_queue<pair<int,string>> maxFreqHeap;
        deque<pair<string,int>> freqQue;
        vector<string> ans;
        
        for(string word : words){
            freqMap[word]++;
        }
    
        
        for(auto wordKey : freqMap){
            int count = wordKey.second;
            string word = wordKey.first;
            maxFreqHeap.push({count, word});
        }
        
        while(!maxFreqHeap.empty()){
            freqQue.push_back({maxFreqHeap.top().second,maxFreqHeap.top().first});
            maxFreqHeap.pop();
        }
        
        sort(freqQue.begin() , freqQue.end() , myCmp);
        
        for(int i=0; i< k; i++){
            ans.push_back(freqQue[i].first);
        }
        
        return ans;
    }
};

// O(nlogk) Approach MinHeap

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> dict;
        for(const string& s:words) dict[s]++;
        
        priority_queue<pair<string,int>, vector<pair<string,int>>, Comp> pq;
        for(const auto& pa:dict) {
            pq.push(pa);
            if(pq.size()>k) pq.pop();
        }    
        
        vector<string> result;
        while(!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        reverse(result.begin(),result.end());    
        return result;    
    }
private:
    struct Comp {
        bool operator()(const pair<string,int>& a, const pair<string,int>& b) {
            return a.second>b.second || (a.second==b.second && a.first<b.first);
        }
    };
};
