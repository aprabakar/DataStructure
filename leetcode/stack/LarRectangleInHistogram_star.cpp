// leet -> https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int ans = INT_MIN;
        int currTopPos, currMaxHeight;
        for(int i=0 ; i< heights.size(); i++){
            while(st.top() != -1 && heights[st.top()] > heights[i]){
                currTopPos = st.top();
                st.pop();
                // [5,4,3,2] [1,5,6,2]
                currMaxHeight = heights[currTopPos] * (i-st.top()-1);
                cout<<" val = "<<heights[currTopPos]<<" currMaxHeight = "<<currMaxHeight<<endl;
                ans = max(ans, currMaxHeight);
            }
            st.push(i);
        }
        
        
        while(st.top() != -1){
            int lastPos = st.top();
            st.pop();
            int length = heights.size()-st.top()-1;
            currMaxHeight = heights[lastPos] * length;
            ans = max(ans, currMaxHeight);                    
        }
        
        return ans;
    }
};
