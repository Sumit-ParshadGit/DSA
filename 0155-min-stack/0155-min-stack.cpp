class MinStack {
public:
    vector<int>st;
    int m = INT_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push_back(value);
        m = min(m,value);
    }
    
    void pop() {
        int n = st.size();
        if(!n)return ;
        if(st[n-1]==m){
            m=INT_MAX;
            for(int i = 0;i<n-1;i++){
                m=min(m,st[i]);
            }
        }
        st.resize(n-1);
    }
    
    int top() {
        int n = st.size();
        if(!n)return 0;
        return st[n-1];
    }
    
    int getMin() {
        return m;
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