// leet -> https://leetcode.com/problems/magnetic-force-between-two-balls/
class Solution {
public:
    
    int checkPossibility(vector<int>& position, int curr_distance , int balls) {
        int ans = 1, cur = position[0];
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - cur >= curr_distance) {
                ans++;
                cur = position[i];
            }
        }
       // cout<< "ans = "<<ans<<" curr_distance= "<<curr_distance<<endl;
        return (ans >= balls);
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 0, r = position.back() - position.front();
        while (l < r) {
            int mid = r - (r - l) / 2;
            if (checkPossibility(position, mid , m))
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};
