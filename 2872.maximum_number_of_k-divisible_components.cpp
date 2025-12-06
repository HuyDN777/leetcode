class Solution {
public:
    int ans = 0; 
    long long dfs(int currentNode, int parentNode, vector<vector<int>>& adj, vector<int>& values, int k) {
        long long currentSum = values[currentNode];
        for (int neighbor : adj[currentNode]) {
            if (neighbor != parentNode) currentSum += dfs(neighbor, currentNode, adj, values, k);
        }
        if (currentSum % k == 0) {
            ans++; 
            return 0; 
        }
        return currentSum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1, adj, values, k);

        return ans;
    }
};