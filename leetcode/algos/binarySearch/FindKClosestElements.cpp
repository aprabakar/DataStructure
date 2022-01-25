//leet-> https://leetcode.com/problems/find-k-closest-elements/

// Binary Search

// case 1: x - A[mid] < A[mid + k] - x, need to move window go left
// -------x----A[mid]-----------------A[mid + k]----------

// case 2: x - A[mid] < A[mid + k] - x, need to move window go left again
// -------A[mid]----x-----------------A[mid + k]----------

// case 3: x - A[mid] > A[mid + k] - x, need to move window go right
// -------A[mid]------------------x---A[mid + k]----------

// case 4: x - A[mid] > A[mid + k] - x, need to move window go right
// -------A[mid]---------------------A[mid + k]----x------

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        while (left < right) {
            int mid = (left + right) / 2;
            if (x - arr[mid] > arr[mid + k] - x)
                left = mid + 1;
            else
                right = mid;
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
