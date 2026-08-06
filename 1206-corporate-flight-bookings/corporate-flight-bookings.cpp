class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n+1,0);

        for(auto it : bookings){
            int first=it[0];
            int last=it[1];
            int seats=it[2];

            ans[first]+=seats;
            if(last+1 <=n)
            ans[last+1]-=seats;

        }
        vector<int> v;
        int prefix=0;
        for(int i=1;i<ans.size();i++){
            prefix+=ans[i];
            v.push_back(prefix);
        }

        return v;

    


    }
};