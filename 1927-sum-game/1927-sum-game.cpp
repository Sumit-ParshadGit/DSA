class Solution {
public:
    bool sumGame(string num) {
       int ls,rs;
        ls =rs = 0;
       int lq,rq;
        lq =rq = 0;
        int n = num.size();
        for(int i  = 0;i<n;i++){
            if(i<n/2){
                if(num[i]=='?')lq++;
                else ls+=num[i]-'0';
            }else{
                if(num[i]=='?')rq++;
                else rs+=num[i]-'0';
            }
        }
        return (lq+rq)%2==1 || (ls-rs)!=(rq-lq)/2*9;
    }
};