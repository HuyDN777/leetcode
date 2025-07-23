class Solution {
public:
    int bfs(int u, vector<vector<int>>& graph) {
        int maxDepth = 0;
        queue<int> q;
        vector<int> visited(graph.size(), 0);

        q.push(u);
        visited[u] = 1;
        int depth = 0;

        while (!q.empty()) {
            int size = q.size();
            depth++;
            for (int i = 0; i < size; ++i) {
                int node = q.front(); q.pop();
                for (int neighbor : graph[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = 1;
                        q.push(neighbor);
                    }
                }
            }
        }

        return depth;
    }

    bool isBipartite(vector<vector<int>>& graph, int start, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (int neighbor : graph[node]) {
                if (color[neighbor] == -1) {
                    color[neighbor] = color[node] ^ 1;
                    q.push(neighbor);
                } else if (color[neighbor] == color[node]) {
                    return false;
                }
            }
        }

        return true;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n + 1, false);
        int result = 0;

        for (int i = 1; i <= n; ++i) {
            if (visited[i]) continue;

            vector<int> component;
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int node = q.front(); q.pop();
                component.push_back(node);
                for (int neighbor : graph[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            vector<int> color(n + 1, -1);
            if (!isBipartite(graph, component[0], color)) {
                return -1;
            }
            int maxGroup = 0;
            for (int node : component) {
                maxGroup = max(maxGroup, bfs(node, graph));
            }

            result += maxGroup;
        }

        return result;
    }
};
