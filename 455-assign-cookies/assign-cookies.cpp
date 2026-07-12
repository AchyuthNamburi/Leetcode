class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=s.size();
        sort(g.rbegin(),g.rend());
        sort(s.rbegin(),s.rend());

        int i=0;
        int j=0;

        int cnt=0;

        while(i<s.size() && j<g.size()){
            if(s[i]>=g[j]){
                i++;
                j++;
                cnt++;
            }
            else{
                j++;
            }

        }

        return cnt;
    }
};