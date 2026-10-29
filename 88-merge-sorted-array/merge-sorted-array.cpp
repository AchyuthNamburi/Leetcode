class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // int i=0;
        // int j=0;

        // while(i<m+n && j<n){
        //     if(nums1[i]>nums2[j]){
        //         nums1[m+j]=nums2[j];
        //         j++;
        //     }
        //     else{
        //         i++;
        //     }
        // }
        int j=0;
        for(auto it: nums2){
            nums1[m+j]=it;
            j++;
        }

        sort(nums1.begin(),nums1.end());

    }
};