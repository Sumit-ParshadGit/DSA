class Solution {
public:
    int fun(vector<int>&tmp){
        if(tmp[1]&&tmp[2]&&tmp[3]&&tmp[4]&&tmp[5]&&tmp[6]&&tmp[7]&&tmp[8])return 2;
        if(tmp[1]&&tmp[2]&&tmp[3]&&tmp[4]||tmp[5]&&tmp[6]&&tmp[7]&&tmp[8]||tmp[3]&&tmp[4]&&tmp[5]&&tmp[6])return 1;
        return 0;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        unordered_map<int,vector<int>>mp;
        for(auto&vec:rs){
            mp[vec[0]].push_back(vec[1]);
        }
        int ans = 0;
        int c = 0;
        for(auto&el:mp){
            c++;
            vector<int>tmp(10,1);
            for(int i:el.second){
                tmp[i-1] = 0;
            }
            ans+=fun(tmp);
        }
        ans+=(n-c)*2;
        return ans;
    }
};