class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int sz=target.size();

        vector<string> ans;
        int i=0;

        for(int curr=1;curr<=n,i<sz;curr++){
            ans.push_back("Push");

            if(target[i]==curr){
                i++;
            }
            else{
                ans.push_back("Pop");
            }
        }

        return ans;
    }
};