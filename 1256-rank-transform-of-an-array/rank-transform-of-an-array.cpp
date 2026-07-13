class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return {};
        vector<pair<int,int>> pq;

        for(int i=0;i<n;i++){
            pq.push_back({arr[i],i});
        }

        sort(pq.begin(),pq.end());

        vector<int> rank(n);
        int curr=1;
        rank[pq[0].second]=1;

        for(int i=1;i<n;i++){
            if(pq[i].first!=pq[i-1].first){
                curr++;
                rank[pq[i].second]=curr;
            }
            else{
                rank[pq[i].second]=curr;
            }
        }

        return rank;
    }
};