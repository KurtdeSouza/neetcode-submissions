class MinStack {
private:
    std::vector<int> res;
    std::vector<int> min;
public:

    MinStack() {}
    
    void push(int val) {
        res.push_back(val);
        if(min.size() == 0 || min.back() > val){
            min.push_back(val);
        }else{
            min.push_back(min.back());
        }
    }
    
    void pop() {
        min.pop_back();
        res.pop_back();
    }

    int top() {
        return res.back();
    }
    
    int getMin() {
        return min.back();
    }
};
