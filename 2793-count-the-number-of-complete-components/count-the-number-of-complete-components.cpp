class Solution {
public:
    void dfs(int node,vector<vector<int>>& adjList,vector<int>& visited,vector<int>& components){
        components.push_back(node);
        visited[node]=true;
        for(auto neigh:adjList[node]){
            if(!visited[neigh]){
                 dfs(neigh,adjList,visited,components);
            }
           
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
       
       for(auto it : edges){
           int u=it[0];
           int v=it[1];
           
           adjList[u].push_back(v);
           adjList[v].push_back(u);
       }
       
       vector<int> visited(n,0);
       vector<vector<int>> all_components;
       for(int i=0;i<n;i++){
        vector<int> components;
            if(!visited[i]){
                dfs(i,adjList,visited,components);
                all_components.push_back(components);
            }
       }

        int cnt=0;
       for(int i=0;i<all_components.size();i++){
            int total_edges=0;
            for(int j=0;j<all_components[i].size();j++){
                int curr=all_components[i][j];
                total_edges+=adjList[curr].size();
            }
            total_edges/=2; //since undirected ...double counting
            int v=all_components[i].size();
            if(total_edges==v*(v-1)/2){
                cnt++;
            }

       }

       return cnt;
    }
};