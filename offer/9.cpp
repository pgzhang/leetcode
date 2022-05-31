// Solution 1:
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        rev.push(value);
    }
    
    int deleteHead() {
        if (!que.empty()){
            int res = que.top();
            que.pop();
            return res;
        }
        if (rev.empty()) return -1;
        while(!rev.empty()){
            int temp = rev.top();
            rev.pop();
            que.push(temp);
        }
        int res = que.top();
        que.pop();
        return res;
    }
private:
    std::stack<int> rev;
    std::stack<int> que;
};

// Solution 2:
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int x) {
        s.push(x);
        min_stack.push(::min(min_stack.top(), x));
    }
    
    void pop() {
        s.pop();
        min_stack.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return min_stack.top();
    }
private:
    std::stack<int> s;
    std::stack<int> min_stack;
};