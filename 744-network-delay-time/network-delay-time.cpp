class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // create adjList from Adj matrix

        vector<vector<pair<int,int>>> adjList(n+1);

        for(auto it : times){
            int a=it[0];
            int b=it[1];
            int c=it[2];

            adjList[a].push_back({b,c});
        }

        //{cost,src}
        priority_queue<pair<int,int>,
                        vector<pair<int,int>>,
                        greater<pair<int,int>>> pq; // since dijkstra algo
        vector<int> dis(n+1,1e9);
        dis[k] = 0;  // Important: initialize source distance
        pq.push({0,k});

        while(!pq.empty()){
            int node=pq.top().second;
            int cost=pq.top().first;
            pq.pop();

            if(cost > dis[node]) continue;

            for(auto neigh:adjList[node]){
                int v=neigh.first;
                int wt=neigh.second;

                if(dis[v] > dis[node]+wt ){
                    dis[v]=dis[node]+wt;
                    pq.push({dis[v],v});
                }

            }
        }

        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            maxi=max(maxi,dis[i]);
        }

        return maxi==1e9 ? -1 : maxi; 

    }
};