// leet- > https://leetcode.com/explore/learn/card/binary-search/125/template-i/950/ 
//Return the square root of x
class Solution {
public:
    int mySqrt(int x) {
                
        long left = 0 , right = x ,ans;
        
        while(left <= right){
            long mid = (left+right) / 2;
            
            if(mid* mid == x){
                return mid;
            }
            
            if(mid* mid < x){
               left = mid+1; 
               ans = mid; 
            }else{
               right = mid-1; 
            }
        }
        
        return ans;
        
    }
};
