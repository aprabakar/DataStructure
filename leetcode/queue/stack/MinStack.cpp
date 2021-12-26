// Approach 1 (Two stacks)

class MinStack {
    vector<int> data;
    vector<int> minelePos;
public:
    void push(int val) {
        if(minelePos.empty() || val < data[minelePos.back()]){
           minelePos.push_back(data.size()); 
        } 
        data.push_back(val);
    }
    
    void pop() {
        data.pop_back();
        if(minelePos.back() == data.size()){
            minelePos.pop_back();
        }
    }

    int top() {
        return data.back(); 
    }
    int getMin() { 
        return data[minelePos.back()]; 
    }
};

//Approach 2 (pair)

class MinStack {
     stack<pair<int, int>> st;

public:
    void push(int x) {
        int min;
        if (st.empty()) {
            min = x;
        }
        else {
            min = std::min(st.top().second,x);
        }
        st.push({x, min});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};
