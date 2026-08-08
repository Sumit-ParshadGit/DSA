class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int>lst(m,-1);
        int j = m-1;
        for(int i = n-1;i>=0&&j>=0;i--){
            if(word1[i]==word2[j]){
                lst[j] = i;
                j--;
            }
        }
        vector<int>ans;
        int f = 1;
        j = 0;
        for(int i = 0;i<n;i++){
            if(j<m){
                if(word1[i]==word2[j]||(f==1&&(j==m-1||i+1<=lst[j+1]))){
                    if(word1[i]!=word2[j])f = 0;
                    ans.push_back(i);
                    j++;
                }
            }
        }
        return ans.size()==m?ans:vector<int>();
    }
};