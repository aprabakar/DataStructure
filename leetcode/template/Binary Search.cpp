// Standard binary search
int search(vector<int>& nums, int target) {
        int left = 0 , right = nums.size()-1, mid;

        while(left <= right){
            mid = (left +right) /2;

            if(nums[mid] == target){
                return mid;
            }

            if(nums[mid] > target){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        return -1;
}

//Another variation
long left = 0 , right = nums.size()-1, mid;

  while (left < right){
     mid =  (left + right + 1) / 2;
     if(nums[mid] > nums[mid-1]){
         left = mid;
     }else{
         right = mid-1;
     }
  }

return left;


//Boundary as same number
https://leetcode.com/problems/sqrtx/
int mySqrt(int x) {
      long low = 0 , end = x, mid;

      while(low < end){
          mid = (low+end) / 2;

          if(mid*mid == x){
              return mid;
          }

          if(mid*mid > x){
              end = mid;
          }else{
              low = mid+1;
          }
      }

      return low*low > x ? low-1 : low;
}

// Search space using end
//https://leetcode.com/problems/single-element-in-a-sorted-array/
int singleNonDuplicate(vector<int>& nums) {
      int low =0 , end = nums.size()-1, mid;

      //solved in 30 mins
      while(low < end){
          mid = (low+end)/2;

          //same+even || //diff+odd
          bool isValidEnd = (mid+1 <= end) && 
                              ((nums[mid+1] == nums[mid]) && (nums.size()-mid-1)%2 == 0) 
                                  || ((nums[mid+1] != nums[mid]) && (nums.size()-mid-1)%2 != 0)? true : false;

          if(isValidEnd){
              low = mid+1;
          }else{
              end = mid;
          }
      }
      return nums[low];
}

// search over matrix
// https://leetcode.com/problems/search-a-2d-matrix/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int row_num = matrix.size();
      int col_num = matrix[0].size();
      
      int begin = 0, end = row_num * col_num - 1;
      
      while(begin <= end){
          int mid = (begin + end) / 2;
          int mid_value = matrix[mid/col_num][mid%col_num];
          
          if( mid_value == target){
              return true;
          
          }else if(mid_value < target){
              begin = mid+1;
          }else{
              end = mid-1;
          }
      }
      
      return false;
}

// search duplicate with rotation
//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
int search(vector<int>& nums, int target) {
        int st =0 , en = nums.size()-1, mid;
        
        if(nums.size() == 1){
            return (nums[0] == target) ? 0 : -1;
        }
        
        while(st < en){
            mid = (st + en) / 2;
        
            if(nums[mid] == target){
                return mid;
            }
        
            if(nums[st] == target){
                return st;
            }
        
            if(nums[en] == target){
                return en;
            }
        
            if(nums[mid] > nums[st] && !(target<nums[mid] && target>nums[st]) || 
                (nums[mid] < nums[en] && (target>nums[mid] && target<nums[en]))){
                st = mid+1;
            }else{
                en = mid-1;
            }
        }
        
        return -1;
}


//Problems:

https://leetcode.com/problems/single-element-in-a-sorted-array/description/
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
https://leetcode.com/problems/find-peak-element/description/
https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/
https://leetcode.com/problems/search-a-2d-matrix/
https://leetcode.com/problems/koko-eating-bananas/description/
https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/
https://leetcode.com/problems/search-in-rotated-sorted-array/description/
https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
