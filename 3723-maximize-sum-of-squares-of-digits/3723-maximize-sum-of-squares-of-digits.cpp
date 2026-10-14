class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        vector<int>tmp;
        while (sum>0){
            tmp.push_back(min(sum,9));
            sum-=9;
        }
        if(tmp.size()>num)return ans;
        int d=num-tmp.size();
        while(d){
            tmp.push_back(0);
            d--;
        }
        for(int x :tmp){
            string ch=to_string(x);
            ans+=ch;
        }
        return ans;
    }
};