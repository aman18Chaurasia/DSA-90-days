#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    struct Node {
        int mn, mx, lazy;
    };
    vector<Node> tree;

    void apply(int u, int val) {
        tree[u].mn += val;
        tree[u].mx += val;
        tree[u].lazy += val;
    }

    void pushdown(int u) {
        if (tree[u].lazy != 0) {
            apply(u << 1, tree[u].lazy);
            apply(u << 1 | 1, tree[u].lazy);
            tree[u].lazy = 0;
        }
    }

    void pushup(int u) {
        tree[u].mn = min(tree[u << 1].mn, tree[u << 1 | 1].mn);
        tree[u].mx = max(tree[u << 1].mx, tree[u << 1 | 1].mx);
    }

    void update(int u, int l, int r, int ql, int qr, int val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(u, val);
            return;
        }
        pushdown(u);
        int mid = (l + r) >> 1;
        update(u << 1, l, mid, ql, qr, val);
        update(u << 1 | 1, mid + 1, r, ql, qr, val);
        pushup(u);
    }

    int query(int u, int l, int r, int target) {
        // If target is not in the range [min, max] of this node, it's not here
        if (tree[u].mn > target || tree[u].mx < target) return -1;
        if (l == r) return l;
        pushdown(u);
        int mid = (l + r) >> 1;
        // Search left child first for the earliest index
        int res = query(u << 1, l, mid, target);
        if (res != -1) return res;
        return query(u << 1 | 1, mid + 1, r, target);
    }

public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        // Segment tree covers indices 0 to n (prefix sum indices)
        tree.assign(4 * (n + 1), {0, 0, 0});
        vector<int> last_pos(100005, -1);
        int current_total = 0;
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            int det = (x % 2 != 0) ? 1 : -1;

            // If we've seen this number, revoke its previous "distinct" contribution
            if (last_pos[x] != -1) {
                update(1, 0, n, last_pos[x] + 1, n, -det);
                current_total -= det;
            }

            // Mark current index as the new "last occurrence"
            last_pos[x] = i;
            update(1, 0, n, i + 1, n, det);
            current_total += det;

            // Find the earliest prefix sum index j such that S[j] == current_S
            int first_idx = query(1, 0, n, current_total);
            if (first_idx != -1) {
                ans = max(ans, (i + 1) - first_idx);
            }
        }
        return ans;
    }
};