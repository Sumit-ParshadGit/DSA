class Solution {
public:
    int smallestNumber(int n, int t) {
        while(1){
            int pro = 1;
            int tmp = n;
            while(tmp){
                pro*=tmp%10;
                tmp/=10;
            }
            if(pro%t==0)return n;
            n+=1;
        }return -1;
    }
};