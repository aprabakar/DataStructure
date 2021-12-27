//Double Queue

// class MyStack {
// public:
//     queue<int> first;
//     queue<int> second;
//     MyStack() {
//         first = queue<int>();
//         second = queue<int>();
//     }
    
//     void push(int x) {
//         while(!first.empty()){
//             second.push(first.front());
//             first.pop();
//         }
        
//         first.push(x);
        
//         while(!second.empty()){
//             first.push(second.front());
//             second.pop();
//         }
//     }
    
//     int pop() {
//         int popEle = first.front();
//         first.pop();
//         return popEle;
//     }
    
//     int top() {
//         return first.front();
//     }
    
//     bool empty() {
//         return first.empty();
//     }
// };

//single queue pop heavy approach

// class MyStack {
// public:
//     queue<int> first;
//     MyStack() {
//         first = queue<int>();
//     }
    
//     void push(int x) {
//         first.push(x);
//     }
    
//     int pop() {
//         int count = 0;
//         int popEle,ele;
//         while(count < first.size()-1){
//             ele = first.front();
//             first.pop();
//             first.push(ele);
//             count++;
//         }
//         popEle = first.front();
//         first.pop();
//         return popEle;
//     }
    
//     int top() {
//         int topEle = pop();
//         first.push(topEle);
//         return topEle;
//     }
    
//     bool empty() {
//         return first.empty();
//     }
// };

//single queue push heavy approach

class MyStack {
public:
	queue<int> first;
    MyStack() {
        first = queue<int>();
    }
    
	void push(int x) {
		first.push(x);
		for(int i=0;i<first.size()-1;++i){
			first.push(first.front());
			first.pop();
		}
	}

	int pop() {
        int topEle = first.front();
        first.pop();
		return topEle;
	}

	int top() {
		return first.front();
	}
    
	bool empty() {
		return first.empty();
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
