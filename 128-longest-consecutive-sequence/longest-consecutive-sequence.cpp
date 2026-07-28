class Solution {
public:
    // they asked for O(n) so we should not do  Sorting !
    // idea is to use Unordered_set

    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();

        if(n==0) return 0;
        
        unordered_set<int> st;

        for(auto it :nums){
            st.insert(it);
        }

        
        int longest=1;
        for(auto it : st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    x=x+1;
                    cnt++;
                }
                longest=max(longest,cnt);
            }  
        }

        return longest;

    }
};