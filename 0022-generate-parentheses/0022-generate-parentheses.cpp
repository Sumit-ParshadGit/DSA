class Solution {
public:
    vector<string>res;
    void sol(int n,int oc,int cc,string tmp){
        if(cc>oc||oc>n)return ;
        if(tmp.size()==2*n){
            res.push_back(tmp);
            return ;
        }
        tmp.push_back('(');
        sol(n,oc+1,cc,tmp);
        tmp.pop_back();
        tmp.push_back(')');
        sol(n,oc,cc+1,tmp);
        tmp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string tmp = "";
        sol(n,0,0,tmp);
        return res;
    }
};