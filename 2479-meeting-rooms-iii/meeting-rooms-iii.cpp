class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& mt) {
        sort(mt.begin(), mt.end());

        priority_queue<int, vector<int>, greater<int>> free;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> busy;

        for (int i = 0; i < n; i++) free.push(i);

        vector<int> cnt(n, 0);

        for (auto &m : mt) {
            long long s = m[0], e = m[1], d = e - s;

            while (!busy.empty() && busy.top().first <= s) {
                free.push(busy.top().second);
                busy.pop();
            }

            if (!free.empty()) {
                int r = free.top(); free.pop();
                busy.push({e, r});
                cnt[r]++;
            } else {
                auto [t, r] = busy.top(); busy.pop();
                busy.push({t + d, r});
                cnt[r]++;
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++)
            if (cnt[i] > cnt[ans]) ans = i;

        return ans;
    }
};
