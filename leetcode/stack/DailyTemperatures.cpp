class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        stack<int> st_pos;
        int i;
        
        //[73,74,75,71,69,72,76,73]
        // 3,2
        for(i=1 ; i< temperatures.size() ; i++){
            if(temperatures[i] > temperatures[i-1]){
                result[i-1] = 1;
                while(!st_pos.empty() && temperatures[i] > temperatures[st_pos.top()]){
                    result[st_pos.top()] = i-st_pos.top();
                    st_pos.pop();
                }
            }else{
                st_pos.push(i-1);
            }
        }
        result[i-1] = 0;
        return result;
    }
};
