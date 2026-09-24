class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int prev=0,curr=0,i=0,j=0;
        int total=n+m;

        for(int count=0;count<=total/2;count++)
        {
            prev=curr;
            if(i!=n && j!=m)
            {
                if(nums1[i]<=nums2[j])
                {
                    curr=nums1[i];
                    i++;
                }
                else
                {
                    curr=nums2[j];
                    j++;
                }
            }
            else if(i<n) curr=nums1[i++];
            else curr=nums2[j++];
        }

        if(total%2==1) return (double)curr;
        else return (double)(curr+prev)/2.0;
    }
};