class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        s.push(x);
        v.push_back(x);
        std::sort(v.begin(), v.end());
    }
    
    void pop() {
        int temp = s.top();
        s.pop();
        v.erase(std::find(v.begin(), v.end(), temp));
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return v[0];
    }
private:
    std::stack<int> s;
    std::vector<int> v;
};