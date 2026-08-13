// class Solution {
// public:
//     int dif(int a,int b){
//         return a-b>=0?a-b:b-a;
//     }
//     int longestSubarray(vector<int>& nums, int lim) {
//         int i = 0;
//         int j = 0;
//         int n = nums.size();
//         int ans = 0;
//         int maw = INT_MIN;
//         int miw = INT_MAX;
//         while(j<n){
//             maw = max(maw,nums[j]);
//             miw = min(miw,nums[j]);
//             if(dif(maw,miw)>lim){
//                 maw = INT_MIN;
//                 miw = INT_MIN;
//                 while(i<j&&(dif(maw,miw))>lim){
//                 i++;
//             }
//             }
//             ans = max(ans,j-i+1);
//             j++;
//         }return ans;
//     }
// };

class Solution {
public:
    int dif(int a,int b){
        return a-b>=0?a-b:b-a;
    }
    int longestSubarray(vector<int>& nums, int lim) {
        priority_queue<pair<int,int>,vector<pair<int,int>>>maxh;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
        int ans = 0;
        int i = 0;
        int j = 0;
        while(j<nums.size()){
            maxh.push({nums[j],j});
            minh.push({nums[j],j});

            while(i<j&&dif(maxh.top().first,minh.top().first)>lim){
                i = min(maxh.top().second,minh.top().second)+1;

                while(maxh.top().second<i)maxh.pop();
                while(minh.top().second<i)minh.pop();
            }
            ans = max(ans,j-i+1);
            j++;
        }return ans;
    }
};