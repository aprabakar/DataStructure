class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int start;
        if(prices.size() == 0 || prices.size() == 1) 
            return 0;
        start = prices[0];
        int max_value = INT_MIN;
        for(int i=1 ;i<prices.size() ;i++)
        {
           max_value = max(max_value , max(0 ,prices[i] - start));
           if(prices[i] < start)
                start = prices[i];
        }
        return max_value;
        
    }
};
