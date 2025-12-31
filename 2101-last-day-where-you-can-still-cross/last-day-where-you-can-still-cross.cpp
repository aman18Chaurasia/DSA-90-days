class DSU {
public:
    vector<int> parent, rankv;

    DSU(int n) {
        parent.resize(n);
        rankv.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (rankv[a] < rankv[b]) swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) rankv[a]++;
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row * col;
        int TOP = n;
        int BOTTOM = n + 1;

        DSU dsu(n + 2);
        vector<vector<bool>> land(row, vector<bool>(col, false));

        vector<int> dir = {0, 1, 0, -1, 0};

        for (int day = cells.size() - 1; day >= 0; day--) {
            int r = cells[day][0] - 1;
            int c = cells[day][1] - 1;
            land[r][c] = true;

            int id = r * col + c;

            if (r == 0) dsu.unite(id, TOP);
            if (r == row - 1) dsu.unite(id, BOTTOM);

            for (int k = 0; k < 4; k++) {
                int nr = r + dir[k];
                int nc = c + dir[k + 1];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col && land[nr][nc]) {
                    int nid = nr * col + nc;
                    dsu.unite(id, nid);
                }
            }

            if (dsu.find(TOP) == dsu.find(BOTTOM)) {
                return day;
            }
        }
        return 0;
    }
};
