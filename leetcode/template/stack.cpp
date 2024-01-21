//monotonic decreasing stack
https://leetcode.com/problems/car-fleet/solutions/1108723/c-detailed-explained-sort-monotonic-stack/

class Car{
public:
    Car(int pos, int speed){
        this->pos = pos;
        this->speed= speed;
    }
    int pos;
    int speed;
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        int N = position.size();
        for(int i = 0; i<N; i++){
            cars.emplace_back(position.at(i), speed.at(i));
        }
        
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b){
            return a.pos<b.pos;
        });
        
        stack<float> mono;
        for(int i = 0; i<N; i++){
            float time = 
                (target-cars.at(i).pos)/(float)cars.at(i).speed;
            while(!mono.empty() && time >= mono.top()){
                mono.pop();
            }
            mono.push(time);
        }
        return mono.size();        
    }
};

// next increasing for max histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int leftsmall[n], rightsmall[n];
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty())
                leftsmall[i] = 0;
            else
                leftsmall[i] = st.top() + 1;
            st.push(i);
        }
        // clear the stack to be re-used
        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty())
                rightsmall[i] = n - 1;
            else
                rightsmall[i] = st.top() - 1;

            st.push(i);
        }
        int maxA = 0;
        for (int i = 0; i < n; i++) {
            maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
        }
        return maxA;
    }
};
