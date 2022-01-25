//leet -> https://leetcode.com/problems/find-k-pairs-with-smallest-sums/


struct mycompare{
    bool operator()(pair<int, int>& p1, pair<int, int>& p2){
        return p1.first + p1.second < p2.first + p2.second;
    }
};
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>, vector<pair<int, int> >, mycompare> pq;
        vector<vector<int>> res;
        for(int i = 0; i < min((int)nums1.size(), k); i++){
            for(int j = 0; j < min((int)nums2.size(), k); j++){
                if(pq.size() < k)
                    pq.push(make_pair(nums1[i], nums2[j]));
                else if(nums1[i] + nums2[j] < pq.top().first + pq.top().second){
                    pq.push(make_pair(nums1[i], nums2[j]));
                    pq.pop();
                }
            }
        }
        while(!pq.empty()){
            pair<int,int> pairSet = pq.top();
            vector<int> pairList;
            pairList.push_back(pairSet.first);
            pairList.push_back(pairSet.second);
            res.push_back(pairList);
            pq.pop();
        }
        return res;
    }
};


//       1   2   5
//    +------------
//  2 |  3   4   7
//  3 |  4   5   8
//  4 |  5   6   9
