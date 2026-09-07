class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (rank[px] > rank[py]) {
            parent[py] = px;
        }
        else if (rank[px] < rank[py]) {
            parent[px] = py;
        }
        else {
            parent[py] = px;
            rank[px]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        vector<int> answer;

        for (auto edge : edges) { // since they asked to return the last in the input...so we are looping through all edges and updating them 

            int u = edge[0];
            int v = edge[1];

            if (find(u) == find(v)) { // redundant edge
                answer = edge;
            }
            else {
                Union(u, v);
            }
        }

        return answer;
    }
};