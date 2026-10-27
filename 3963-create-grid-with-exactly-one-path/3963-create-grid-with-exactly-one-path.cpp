class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector <string>ans;
        for(int i=0;i<m;i++){
            string tmp="";
            for(int j=0;j<n;j++){
                tmp+="#";
            }
            ans.push_back(tmp);
        }
        for(int i=0;i<m;i++)
        ans[i][n-1]='.';
        for(int i=0;i<n;i++)
        ans[0][i]='.';
        return ans;
    }
};
