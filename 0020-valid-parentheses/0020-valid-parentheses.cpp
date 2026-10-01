class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        st.push('a');
        for(char &ch:s){
            if(ch=='['||ch=='{'||ch == '(')st.push(ch);
            else{
                char c = st.top();
                if(c=='('&&ch==')')st.pop();else
                if(c=='{'&&ch=='}')st.pop();else
                if(c=='['&&ch==']')st.pop();
                else return 0;
            }
        }return st.top()=='a'?1:0;
    }
};