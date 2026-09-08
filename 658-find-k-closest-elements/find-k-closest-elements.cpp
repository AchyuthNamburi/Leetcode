class Solution {
public:
    const bool compare(pair<int,int> d_a, pair<int,int> d_b){
        if(abs(d_a.first)<abs(d_b.first)) return d_a.first;
        else if(abs(d_a.first)==abs(d_b.first) && d_a.second<d_b.second) return d_a.first;
        return d_b.first; 

    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        // dist,elem
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(int i=0;i<n;i++){
            int diff=abs(arr[i]-x);
            pq.push({diff,arr[i]});
        }

        vector<int> ans;

        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(),ans.end());

        return ans;



    }
};