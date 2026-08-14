class MinStack {
public:
// The intuition here is to store the top element in minEl whenever we find a value which is smaller than the prev min and instead store 2*val-prevMin in the stack.

// THIS IS THE OPTIMIZATION OF THE PREVIOUS APPROACH WHERE WE USE STACK<INT,INT> ST

// see striver L4 of stacks and queues
// TC -> O(1) and SC-> O(N) -> optimised SC
    int minEl = INT_MAX;
    stack<long long> st;
    MinStack() {
        
    }
    
    void push(int value) {
        long long val = value;
        if (st.empty()) {
            st.push(val);
            minEl = val;
            return;
        }
        if(val<minEl){
            st.push((val-minEl)+val);
            minEl = val;
        }
        else{st.push(val);}
    }
    
    void pop() {
        if(minEl>st.top()){
            minEl = (int)((minEl - st.top())+ minEl);
        }
        st.pop();
        if (st.empty()) {
            minEl = INT_MAX;
        }
    }
    
    int top() {
        if(st.top()<minEl){return minEl;}
        else{return (int)st.top();}
        
    }
    
    int getMin() {
        return (int)minEl;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */