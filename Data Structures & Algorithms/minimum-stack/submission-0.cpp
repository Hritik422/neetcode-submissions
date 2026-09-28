class MinStack {
private:
    vector<pair<int,int>>v;
    int cur=-1;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(cur==-1)v.push_back({val, val});
        else v.push_back({val, min(v[cur].second, val)});
        cur++;
    }
    
    void pop() {
        v.pop_back();
        cur--;
    }
    
    int top() {
        return v[cur].first;
    }
    
    int getMin() {
        return v[cur].second;
    }
};
