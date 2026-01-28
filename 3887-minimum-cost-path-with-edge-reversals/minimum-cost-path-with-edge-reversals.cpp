class Solution {
public:
    long long minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        vector<vector<pair<int, int>>> rev_adj(n);
        
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            rev_adj[edge[1]].push_back({edge[0], edge[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, -1);

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            pair<long long, int> top = pq.top();
            long long d = top.first;
            int u = top.second;
            pq.pop();

            if (dist[u] != -1 && d > dist[u]) continue;
            if (u == n - 1) return d;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                long long weight = edge.second;
                if (dist[v] == -1 || d + weight < dist[v]) {
                    dist[v] = d + weight;
                    pq.push({dist[v], v});
                }
            }

            for (auto& edge : rev_adj[u]) {
                int v = edge.first;
                long long weight = 2LL * edge.second;
                if (dist[v] == -1 || d + weight < dist[v]) {
                    dist[v] = d + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1];
    }
};