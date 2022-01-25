// leet-> https://leetcode.com/problems/distant-barcodes/

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> countMap;
        priority_queue<pair<int,int>> maxHeap;
        vector<int> result(barcodes.size(),0);
        
        for(int i=0 ; i< barcodes.size() ; i++){
            countMap[barcodes[i]]++;
        }
        
        for(auto node : countMap){
            maxHeap.push({node.second, node.first});
        }
        
        int  curr_pos = 0;
        bool isChanged = false;
        while(!maxHeap.empty()){
            
            pair<int,int> pairSet = maxHeap.top();
            maxHeap.pop();
            
            int count = pairSet.first;
            int ele = pairSet.second;
            
            while(count--){
                //cout<<"curr_pos = "<<curr_pos<<endl;
                result[curr_pos] = ele;
                curr_pos += 2;
                
                if(curr_pos >= barcodes.size() && !isChanged){
                    curr_pos = 1;
                    isChanged = true;
                }                
            }   
        }
    
        // even -> 0,2,4
        // odd -> 1,3,5
        
        return result;     
    }
};
