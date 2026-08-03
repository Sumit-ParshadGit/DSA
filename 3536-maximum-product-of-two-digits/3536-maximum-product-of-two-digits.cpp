class Solution {
public:
    int maxProduct(int n) {
        int m1=-1;
        int m2=-1;
        while(n){
            int t = n%10;
            if(t>=m1){
                m2 = m1;
                m1 = t;
            }else m2 = max(m2,t);
            n/=10;
        }return  m1*m2;
    }
};