// leet -> https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/

// Binary Search O(NlogN)
class Solution {
public:
    
    int binarySearch(vector<int>& nums2, int left , int right , int val){
        int ans = -1 , mid , initialLeft;
        
        initialLeft = left;
        while(left <= right){
            mid = (left + right)/2;
            
            if(nums2[mid] >= val){
               ans = max(ans, mid);
               left = mid+1; 
            }else{
               right = mid-1;
            }
        }
        
        return (ans == -1) ? 0 : right-initialLeft;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        // [55,30,5,4,2]
        // [100,20,10,10,5]
        int maxIndex = INT_MIN;
        for(int i= 0 ; i< nums1.size() ; i++){
            if(maxIndex != INT_MIN && maxIndex >= (nums2.size()-i-1)){
                break;
            }            
            maxIndex = max(maxIndex , binarySearch(nums2,i,nums2.size()-1,nums1[i]));
        }
        
        return maxIndex;
    }
    
};


// Two Pointer O(N)
class Solution {
public:
    
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, res = 0, n = nums1.size(), m = nums2.size();
        while (i < n && j < m) {
            if (nums1[i] > nums2[j]){
                i++;
            }else{
               res = max(res, j- i); 
               j++;
            }   
        }
        return res;
    }
    
};
