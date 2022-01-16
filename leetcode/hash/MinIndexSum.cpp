class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        unordered_map<string, int> map;
        int minIndex = INT_MAX;
        vector<string> result;
        
        for(int i= 0 ; i < list1.size() ; i++){
            if(!map.count(list1[i])){
                map[list1[i]] = i;
            }
        }
        
        for(int i= 0 ; i < list2.size() ; i++){
            if(map.count(list2[i])){
                int currMinIndex = i+ map[list2[i]];
                
                if(currMinIndex == minIndex){
                   result.push_back(list2[i]); 
                }
                
                if(currMinIndex < minIndex){
                    result.clear();
                    result.push_back(list2[i]);
                    minIndex = currMinIndex;
                }
            }
        }
        
        return result;
    }
};
