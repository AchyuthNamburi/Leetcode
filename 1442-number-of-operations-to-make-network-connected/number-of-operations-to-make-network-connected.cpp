class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

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

    int makeConnected(int n, vector<vector<int>>& connections) {

        // Not enough cables
        if (connections.size() < n - 1)
            return -1;

        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int extra = 0;

        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];

            if (find(u) == find(v)) {
                // Redundant cable
                extra++;
            }
            else {
                Union(u, v);
            }
        }

        // Count number of components
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                components++;
        }

        int required = components - 1;

        if (extra >= required)
            return required;

        return -1;
    }
};