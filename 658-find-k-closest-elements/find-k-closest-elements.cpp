class Solution {
public:
    struct compare {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        if (a.first != b.first)
            return a.first > b.first;

        return a.second > b.second;
        }
    };
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        // dist,elem
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;

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