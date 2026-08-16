class Solution {
public:
    int dif(int a,int b){
        return a-b>=0?a-b:b-a;
    }
    bool stoneGameIX(vector<int>& stones) {
        vector<int>cnt(3,0);
        for(auto&el:stones){
            cnt[el%3]++;
        }
        if(cnt[0]%2==0)return cnt[1]>0&&cnt[2]>0;
        return dif(cnt[1],cnt[2])>2;
    }
};