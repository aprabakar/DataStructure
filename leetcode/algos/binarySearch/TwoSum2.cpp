class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        //Base case
        
        //Initializations
        int start = 0 , end = numbers.size() -1;
        vector<int> result;
        
        while(start <= end){
            int currVal = numbers[start] + numbers[end];
            if(currVal == target){
                break;
            }else if(currVal < target){
                start++;
            }else{
                end--;
            }
        }
        result.push_back(start+1);
        result.push_back(end+1);
        return result;
        
    }
};
