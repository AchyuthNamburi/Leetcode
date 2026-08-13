class Solution {
public:
    vector<vector<int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        // BFS works for unweighted graphs, but here the cost varies per edge
        // so we have to use Dijkstra algo here 

        int m=heights.size();
        int n=heights[0].size();

        vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
        //effort , x , y
        priority_queue<pair<int,pair<int,int>>,
                        vector<pair<int,pair<int,int>>>,
                        greater<pair<int,pair<int,int>>>
                        > q; // min_heap ...since dijkstra uses min value node only

        q.push({0,{0,0}});
        dis[0][0]=0;

        while(!q.empty()){
            int eff=q.top().first;
            int x=q.top().second.first;
            int y=q.top().second.second;
            q.pop();

            if(x==m-1 && y==n-1) return eff; //reached last
            if(eff>dis[x][y]) continue; //skip if we find the better path already

            for(int i=0;i<4;i++){
                int new_x=x+dir[i][0];
                int new_y=y+dir[i][1];

                if(new_x>=0 && new_x<m && new_y>=0 && new_y<n ){

                    int diff=abs(heights[x][y]-heights[new_x][new_y]);
                    int new_eff=max(eff,diff);

                    if(new_eff<dis[new_x][new_y]){
                        dis[new_x][new_y]=new_eff;
                         q.push({new_eff,{new_x,new_y}});
                    }
                   
                }
            }
        }

        return -1;

    }
};