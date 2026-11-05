class Solution {
public:
    int bs(int x,vector<int>& arr2){
        int i= 0;
        int j = arr2.size()-1;
        int d = INT_MAX;
        while(i<=j){
            int m = i+(j-i)/2;
            d = min(d,abs(arr2[m]-x));
            if(d==0)return 0;
            if(arr2[m]<x){
                i = m+1;
            }else j = m-1;
        }
        return d;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int ans = 0;
        for(int x:arr1){
            if(bs(x,arr2)>d)ans++;
        }return ans;
    }
};