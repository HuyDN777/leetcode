class Solution {
    public:
        int minCost(int n, vector<vector<int>>& edges) {
            vector<vector<pair<int, int>>> adj(n);
            for (auto& e : edges) {
                int u = e[0], v = e[1], w = e[2];
                adj[u].push_back({v, w});
                adj[v].push_back({u, 2 * w});
            }
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
            vector<long long> dist(n, -1);
            pq.push({0, 0});
            dist[0] = 0;
            while (!pq.empty()) {
                long long d = pq.top().first;
                int u = pq.top().second;
                pq.pop();
                if (d > dist[u] && dist[u] != -1) continue;
                if (u == n - 1) return d;
                for (auto& edge : adj[u]) {
                    int v = edge.first;
                    int weight = edge.second;
                    if (dist[v] == -1 || dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                        pq.push({dist[v], v});
                    }
                }
            }
            return -1;
        }
    };