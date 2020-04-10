class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        // No operations
    }
    
    void push(int x) {
        if (stack.empty()) {
            stack.push_back({x, x});
        } else {
            stack.push_back({x, min(x, stack[(int) stack.size() - 1].second)});
        }
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack[(int) stack.size() - 1].first;
    }
    
    int getMin() {
        return stack[(int) stack.size() - 1].second;
    }
private:
    vector<pair<int, int>> stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
