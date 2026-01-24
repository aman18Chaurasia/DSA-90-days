class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre(n), nxt(n);
        for (int i = 0; i < n; i++) {
            pre[i] = i - 1;
            nxt[i] = i + 1;
        }

        vector<long long> a(nums.begin(), nums.end());

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<>
        > pq;

        int bad = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) bad++;
            pq.push({a[i] + a[i + 1], i});
        }

        int operations = 0;

        while (bad > 0) {
            auto [sum, l] = pq.top();
            pq.pop();

            int r = nxt[l];

            if (r >= n || pre[r] != l || a[l] + a[r] != sum)
                continue;

            operations++;

            if (a[l] > a[r]) bad--;
            if (nxt[r] < n && a[r] > a[nxt[r]]) bad--;
            if (pre[l] >= 0 && a[pre[l]] > a[l]) bad--;

            a[r] = sum;

            if (pre[l] >= 0) {
                pre[r] = pre[l];
                nxt[pre[l]] = r;

                if (a[pre[r]] > a[r]) bad++;
                pq.push({a[pre[r]] + a[r], pre[r]});
            } else {
                pre[r] = -1;
            }

            if (nxt[r] < n) {
                if (a[r] > a[nxt[r]]) bad++;
                pq.push({a[r] + a[nxt[r]], r});
            }
        }

        return operations;
    }
};
