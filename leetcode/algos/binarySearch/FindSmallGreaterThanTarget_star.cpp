// leet -> https://leetcode.com/explore/learn/card/binary-search/137/conclusion/977/
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans;
        int left = 0, right =letters.size()-1;
        
        while(left <= right){
            int mid = (left + right) / 2;
            
            if(letters[mid] > target){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        
        if(left >= letters.size()){
            ans = letters[0];
        }else if(letters[left] == target){
            ans = letters[(left+1) % letters.size()];
        }else{
            ans = letters[left];
        }
        
        return ans;
    }
};
