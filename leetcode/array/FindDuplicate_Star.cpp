// leet -> https://leetcode.com/problems/find-the-duplicate-number/

// O(N log N) - Binary search

// Think of numbers on a number line - 1, 2, 3, ..., N - now we add a number to N+1th position but this number is from the range [1, N] thus resulting in a duplicate. This hols for any N.
// So number of elements <= i are either i or i+1 if a number <= i is duplicated. Now in our problem a duplicate can occur more than 2 times.

// In the above solution:

// if the number of elements <= mid are less than mid, i.e., a number greater than mid is occupying a position which should have been occupied by [0, mid] => duplicate in [mid+1,N]
// else, duplicate in [0, mid-1] since the count of elements less than mid is more.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1;
        while (low <= high) {
            int mid = (int) (low + (high - low) * 0.5);
            int cnt = 0;
            for (int a : nums) {
                if (a <= mid) ++cnt;
            }
            if (cnt <= mid) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
    
    // 1 2 3 4
    // 6
    // 7
};


// O(N) - cycle Tortoise principle
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() > 1)
        {
        int slow = nums[0];
        int fast = nums[nums[0]];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = 0;
        while (fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
        }
        return -1;
    }
};
