#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int K) {
        int m = grid.size();
        int n = grid[0].size();
        int MN = m * n;

        // flatten values and build compressed value index
        vector<int> vals;
        vals.reserve(MN);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                vals.push_back(grid[i][j]);
        vector<int> uniq = vals;
        sort(uniq.begin(), uniq.end());
        uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());
        int V = uniq.size();

        auto idx = [&](int i, int j){ return i * n + j; };
        vector<int> valIdx(MN);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                valIdx[idx(i,j)] = lower_bound(uniq.begin(), uniq.end(), grid[i][j]) - uniq.begin();

        // dp_prev holds best costs using <= t-1 teleports; initialize t=0 (no teleports)
        vector<ll> dp_prev(MN, INF), dp_curr(MN, INF);
        dp_prev[idx(0,0)] = 0;
        // t=0: only normal moves (right/down)
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int u = idx(i,j);
                if (i > 0) dp_prev[u] = min(dp_prev[u], dp_prev[idx(i-1,j)] + (ll)grid[i][j]);
                if (j > 0) dp_prev[u] = min(dp_prev[u], dp_prev[idx(i,j-1)] + (ll)grid[i][j]);
            }
        }

        // For each teleport usage 1..K compute dp_curr from dp_prev
        for (int t = 1; t <= K; ++t) {
            // 1) compute minimum dp_prev per value index
            vector<ll> minPerValue(V, INF);
            for (int c = 0; c < MN; ++c) {
                int p = valIdx[c];
                minPerValue[p] = min(minPerValue[p], dp_prev[c]);
            }
            // 2) pref min from high values downwards: pref[p] = min over q >= p of minPerValue[q]
            vector<ll> prefMin(V, INF);
            ll running = INF;
            for (int p = V-1; p >= 0; --p) {
                running = min(running, minPerValue[p]);
                prefMin[p] = running;
            }
            // 3) tele_cost for each cell: best cost to land at that cell by teleporting once (from any cell with >= value)
            vector<ll> teleCost(MN, INF);
            for (int c = 0; c < MN; ++c) {
                teleCost[c] = prefMin[valIdx[c]];
            }
            // 4) initialize dp_curr as min(dp_prev (no extra teleport), teleCost (used one teleport to land here))
            for (int c = 0; c < MN; ++c) dp_curr[c] = min(dp_prev[c], teleCost[c]);

            // 5) propagate normal moves (right/down) across dp_curr
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    int u = idx(i,j);
                    if (i > 0) dp_curr[u] = min(dp_curr[u], dp_curr[idx(i-1,j)] + (ll)grid[i][j]);
                    if (j > 0) dp_curr[u] = min(dp_curr[u], dp_curr[idx(i,j-1)] + (ll)grid[i][j]);
                }
            }

            // move forward: dp_prev <- dp_curr
            dp_prev.swap(dp_curr);
        }

        // answer is best cost at destination using up to K teleports
        return (int)dp_prev[idx(m-1,n-1)];
    }
};
