class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {

        vector<pair<long long, long long>> events;
        long double totalArea = 0;

        for (auto &sq : squares) {
            long long y = sq[1];
            long long l = sq[2];
            totalArea += (long double)l * l;
            events.push_back({y, l});
            events.push_back({y + l, -l});
        }

        sort(events.begin(), events.end());

        long double target = totalArea / 2.0;
        long double area = 0;
        long double slope = 0;

        for (int i = 0; i + 1 < events.size(); i++) {
            slope += events[i].second;
            long double dy = events[i + 1].first - events[i].first;
            long double nextArea = area + slope * dy;

            if (nextArea >= target) {
                long double needed = target - area;
                return (double)(events[i].first + needed / slope);
            }
            area = nextArea;
        }

        return (double)events.back().first;
    }
};
