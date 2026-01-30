class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {

        const long long INF = 1e18;
        int n = source.size();

        unordered_map<string, int> id;
        vector<string> nodes;

        auto getId = [&](const string& s) {
            if (!id.count(s)) {
                id[s] = nodes.size();
                nodes.push_back(s);
            }
            return id[s];
        };

        for (int i = 0; i < original.size(); i++) {
            getId(original[i]);
            getId(changed[i]);
        }

        int m = nodes.size();
        vector<vector<long long>> dist(m, vector<long long>(m, INF));

        for (int i = 0; i < m; i++) dist[i][i] = 0;

        for (int i = 0; i < original.size(); i++) {
            int u = getId(original[i]);
            int v = getId(changed[i]);
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < m; k++)
            for (int i = 0; i < m; i++)
                for (int j = 0; j < m; j++)
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];

        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;

            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            for (int k = 0; k < original.size(); k++) {
                int len = original[k].size();
                if (i + len > n) continue;

                if (source.substr(i, len) == original[k]) {
                    string tgt = target.substr(i, len);
                    if (id.count(tgt)) {
                        long long d = dist[id[original[k]]][id[tgt]];
                        if (d < INF) {
                            dp[i + len] = min(dp[i + len], dp[i] + d);
                        }
                    }
                }
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};
