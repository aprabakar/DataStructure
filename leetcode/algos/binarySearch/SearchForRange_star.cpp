// leet -> https://leetcode.com/explore/learn/card/binary-search/135/template-iii/944/

// My Approach
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return vector<int>(2,-1);
        }
        
        int left = 0 , right = nums.size()-1, ans = INT_MAX , mid;
        
        while(left <= right){
            mid = (left +right) / 2;
            
            if(nums[mid] == target){
                ans = mid;
                break;
            }
            
            if(nums[mid] > target){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        
        if(ans == INT_MAX){
            return vector<int>(2,-1);
        }
        
        left = ans;
        right = ans;
        
        while(left >= 0 && nums[left] == target){
            left--;
        }
        
        while(right < nums.size() && nums[right] == target){
            right++;
        } 
        
        vector<int> result;
        result.push_back(left+1);
        result.push_back(right-1);
        
        return result;
    }
};


// Two Binary Search
class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
	int s = 0, e = a.size()-1;
	vector<int> ans(2, -1);
	//first occurrence
	while(s <= e){
		int m = s + (e-s)/2;
		if(a[m] < target)
			s = m+1;
		else if(a[m] > target)
			e = m-1;
		else{
			if(m == s || a[m] != a[m-1]){
				ans[0] = m;
				break;
			}
			else{
				e = m-1;
				ans[0] = m-1;
			}
		}
	}

	//last occurrence
	s = 0, e = a.size()-1;
	while(s <= e){
		int m = s + (e-s)/2;
		if(a[m] < target)
			s = m+1;
		else if(a[m] > target)
			e = m-1;
		else{
			if(m == e || a[m] != a[m+1]){
				ans[1] = m;
				break;
			}
			else{
				s = m+1;
				ans[1] = m+1;
			}
		}
	}
	return ans; 
}
};
