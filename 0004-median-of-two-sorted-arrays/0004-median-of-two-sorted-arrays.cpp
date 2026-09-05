class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(auto&el:nums2){
            nums1.push_back(0);
        }
        int i = n1-1;
        int j = n2-1;
        int k = i+n2;
        while(i>=0&&j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        while(j>=0){
                nums1[k--] = nums2[j--];
        }
        int n = nums1.size();
        if(nums1.size()%2==0){
            return 1.0*(nums1[n/2]+nums1[n/2-1])/2;
        }
        else return 1.0*nums1[n/2];
    }
};