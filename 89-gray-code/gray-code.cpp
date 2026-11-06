class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans={0}; // only one elem 0 is present ! 

        for(int i=0;i<n;i++){
            int sz=ans.size();

            for(int j=sz-1;j>=0;j--){
                int num= ans[j] | (1<<i) ;
                ans.push_back(num);
            }
        }

        return ans;
    }
};