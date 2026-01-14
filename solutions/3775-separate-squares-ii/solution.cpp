class Solution {
public:

    class SegmentTree {
    public:
        int n;
        vector<int> cover;
        vector<double> len;
        vector<double> xs;

        SegmentTree(const vector<double>& _xs) {
            xs = _xs;
            n = xs.size() - 1;
            cover.assign(4 * n, 0);
            len.assign(4 * n, 0);
        }

        void pull(int node, int l, int r) {
            if (cover[node] > 0) {
                len[node] = xs[r + 1] - xs[l];
            } else if (l == r) {
                len[node] = 0;
            } else {
                len[node] = len[node * 2] + len[node * 2 + 1];
            }
        }

        void update(int node, int l, int r, int ql, int qr, int val) {
            if (qr < l || r < ql) return;
            if (ql <= l && r <= qr) {
                cover[node] += val;
                pull(node, l, r);
                return;
            }
            int mid = (l + r) / 2;
            update(node * 2, l, mid, ql, qr, val);
            update(node * 2 + 1, mid + 1, r, ql, qr, val);
            pull(node, l, r);
        }

        double query() {
            return len[1];
        }
    };

    double separateSquares(vector<vector<int>>& squares) {
        vector<double> xs;
        vector<array<double, 4>> events;

        for (auto& s : squares) {
            double x1 = s[0];
            double x2 = s[0] + s[2];
            double y1 = s[1];
            double y2 = s[1] + s[2];

            xs.push_back(x1);
            xs.push_back(x2);

            events.push_back({y1, +1, x1, x2});
            events.push_back({y2, -1, x1, x2});
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        sort(events.begin(), events.end(),
             [](auto& a, auto& b) { return a[0] < b[0]; });

        SegmentTree seg(xs);

        auto xid = [&](double x) {
            return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        };

        double totalArea = 0;
        double prevY = events[0][0];

        for (auto& e : events) {
            double curY = e[0];
            totalArea += seg.query() * (curY - prevY);

            int l = xid(e[2]);
            int r = xid(e[3]) - 1;
            if (l <= r)
                seg.update(1, 0, seg.n - 1, l, r, e[1]);

            prevY = curY;
        }

        double target = totalArea / 2.0;

        seg = SegmentTree(xs);
        double currArea = 0;
        prevY = events[0][0];

        for (auto& e : events) {
            double curY = e[0];
            double width = seg.query();
            double slice = width * (curY - prevY);

            if (currArea + slice >= target) {
                double remaining = target - currArea;
                return prevY + remaining / width;
            }

            currArea += slice;

            int l = xid(e[2]);
            int r = xid(e[3]) - 1;
            if (l <= r)
                seg.update(1, 0, seg.n - 1, l, r, e[1]);

            prevY = curY;
        }

        return prevY;
    }
};

