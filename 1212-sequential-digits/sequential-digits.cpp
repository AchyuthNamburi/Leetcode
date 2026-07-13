class Solution {
public:
    vector<int> ans;
    void solve(int curr_num,int last_dig,int low,int high){
        if(curr_num>high){
            return;
        }
        if(curr_num>=low){
            ans.push_back(curr_num);
        }
        if(last_dig==9) return;
        solve(curr_num*10+last_dig+1,last_dig+1,low,high);
    }
    vector<int> sequentialDigits(int low, int high) {

        for(int i=1;i<9;i++){
            solve(i,i,low,high);
        }

        sort(ans.begin(),ans.end());

        return ans;  
    }
};