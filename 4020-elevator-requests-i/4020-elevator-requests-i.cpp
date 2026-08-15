class Solution {
public:
    int dif(int a,int b){
        return a-b>=0?a-b:b-a;
    }
    int elevatorRequests(int n, vector<int>& req) {
       int ans = req[0]; 
       for(int i = 1;i<req.size();i++){
        ans += dif(req[i],req[i-1]);
       }return ans;
    }
};