//Min heap with K elements

priority_queue<int, vector<int>, greater<int>> minHeap;

for(int i=0; i < nums.size(); i++){
    if(minHeap.size() < k){
        minHeap.push(nums[i]);
    }else if(minHeap.size() == k && minHeap.top() <= nums[i]){
        minHeap.pop();
        minHeap.push(nums[i]);
    }
}

return minHeap.top();

//Min heap with K elements with pair
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
unordered_map<int, int> mp;

for(int i=0; i< nums.size(); i++){
    if(mp.find(nums[i]) == mp.end()){
        mp[nums[i]] = 1;
    }else{
        mp[nums[i]] += 1;
    }
}

for (auto i = mp.begin(); i != mp.end(); i++){
    if(minHeap.size() < k){
        minHeap.push(make_pair(i->second, i->first));
    }else if(minHeap.size() == k && minHeap.top().first <= i->second){
        minHeap.pop();
        minHeap.push(make_pair(i->second, i->first));
    }
}

vector<int> ans;
for(int i=0; i< k; i++){
    int val = minHeap.top().second;
    ans.push_back(val);
    minHeap.pop();
}

return ans;


//Min heap with K elements with pair with compare func

struct Compfunc {
    bool operator() (const pair<float,int>&x, const pair<float,int>&y) {
        //cout << "a: " << a << " vs b: " << b << endl;
        return x.first < y.first;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,int>, vector<pair<float,int>>, Compfunc> heap;
        vector<vector<int>> ans;

        for(int i=0; i < points.size(); i++){
            float val = sqrt((points[i][0] * points[i][0]) + (points[i][1] * points[i][1]));
            pair<float, int> p = make_pair(val,i);
            if(heap.size() < k){
                heap.push(p);
            }else if(heap.top().first > val){
                heap.pop();
                heap.push(p);
            }
        }

        int count = 0;
        while(heap.size() >= 0 && count < k){
            ans.push_back(points[heap.top().second]);
            heap.pop();
            ++count;
        }

        return ans;
    }
};
