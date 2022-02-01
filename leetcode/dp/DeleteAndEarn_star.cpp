// leet -> https://leetcode.com/problems/delete-and-earn/submissions/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> countMap;
        
        for(int i=0 ; i< nums.size() ; i++){
            countMap[nums[i]]++;
        }
        
        int firstVal = 0, secondVal= 0, count = 0;

        for(int i=1 ; i<= 10000 ; i++){
            if(count == nums.size()){
                break;
            }
            
            if(countMap.find(i) != countMap.end()){
                if(count == 0){
                    secondVal = countMap[i] * i;
                }else{
                    int temp = max((countMap[i] * i) + firstVal , secondVal);
                    firstVal = secondVal;
                    secondVal = temp;
                }
                //cout << "i = "<<i<<" secondVal = "<<secondVal<<endl;
                count++;
            }else{
                firstVal = secondVal;
            }
        }
        
        return secondVal;
    }
};
