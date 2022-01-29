//  leet -> https://leetcode.com/problems/maximum-score-of-a-good-subarray/

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        stack<int> stack;
        stack.push(-1);
        int n = nums.size();
        int ans = nums[k];

        for(int i = 0; i < n; i++) {
           
            while(stack.top() != -1 && nums[stack.top()] >= nums[i]) {
                int currentHeight = nums[stack.top()];
                stack.pop();
                int currentWidth = i - stack.top() - 1;
                
                    // cout<<"First currentHeight = "<<currentHeight
                    //     <<" currentWidth= "<<currentWidth<<endl;
                if(stack.top() < k && i > k){
                    

                    ans = max(ans, currentHeight * currentWidth);
                    
                }
            }
            stack.push(i);
        }
        
        while(stack.top() != -1) {
            int currentHeight = nums[stack.top()];
            stack.pop();
            int currentWidth = n - stack.top() - 1;
                        //         cout<<"second currentHeight = "<<currentHeight
                        // <<" currentWidth= "<<currentWidth<<endl;
            if(stack.top() < k){
                ans = max(ans, currentHeight * currentWidth);
                
            }
        }
        return ans;
    }
};
