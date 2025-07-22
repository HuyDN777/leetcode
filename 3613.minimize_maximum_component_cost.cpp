class Solution {
public:
    vector<int> parent, rank;
    int find(int u) {
        if(u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;
        if(rank[pu] < rank[pv]) swap(pu, pv);
        parent[pv] = pu;
        if(rank[pu] == rank[pv]) rank[pu]++;
        return true;
    }

    int minCost(int n, vector<vector<int>>& edges, int k) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
        sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
            return a[2] < b[2]; 
        });
        vector<int> mst_weights;
        for(auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if(unite(u, v)) mst_weights.push_back(w);
        }
        if(mst_weights.size() < n - 1) return -1;
        sort(mst_weights.begin(), mst_weights.end(), greater<int>()); 

        for(int i = 0; i < k - 1 && !mst_weights.empty(); ++i) {
            mst_weights.erase(mst_weights.begin()); 
        }

        return mst_weights.empty() ? 0 : mst_weights[0];
    }
};