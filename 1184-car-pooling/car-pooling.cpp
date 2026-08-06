class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>dist(1001,0);
        for(auto i : trips){
            int wt = i[0];
            int from = i[1];
            int to = i[2];
            dist[from]+=wt;
            if(to<= 1000)
            dist[to]-=wt;
        }
        // just take prefix sum 
        int sum = 0;
        for(int i=0;i<=1000;i++){
            sum += dist[i];
            if(sum > capacity) return false;
        }
        return true;
    }
};