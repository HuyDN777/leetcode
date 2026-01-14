class Solution {
    struct Node {
        int count;      
        double length; 
    };
    
    vector<Node> tree;
    vector<double> X; 
    void update(int node, int start, int end, int l, int r, int val) {
        if (l >= r) return;
        
        if (start == l && end == r) tree[node].count += val;
        else {
            int mid = (start + end) / 2;
            if (r <= mid) update(node * 2, start, mid, l, r, val);
            else if (l >= mid) update(node * 2 + 1, mid, end, l, r, val);
            else {
                update(node * 2, start, mid, l, mid, val);
                update(node * 2 + 1, mid, end, mid, r, val);
            }
        }
        if (tree[node].count > 0) tree[node].length = X[end] - X[start];
        else {
            if (start + 1 == end) tree[node].length = 0;
            else tree[node].length = tree[node * 2].length + tree[node * 2 + 1].length;
        }
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        struct Event {
            int y, type, x1, x2;
            bool operator<(const Event& other) const {
                return y < other.y;
            }
        };

        vector<Event> events;
        for (const auto& sq : squares) {
            X.push_back(sq[0]);
            X.push_back((double)sq[0] + sq[2]);
            events.push_back({sq[1], 1, sq[0], sq[0] + sq[2]});
            events.push_back({sq[1] + sq[2], -1, sq[0], sq[0] + sq[2]});
        }

        sort(X.begin(), X.end());
        X.erase(unique(X.begin(), X.end()), X.end());
        auto getXIndex = [&](int val) {
            return lower_bound(X.begin(), X.end(), val) - X.begin();
        };
        sort(events.begin(), events.end());

        tree.resize(4 * X.size(), {0, 0.0});
        double totalArea = 0;
        vector<double> layerAreas; 
        
        for (size_t i = 0; i < events.size() - 1; ++i) {
            int u = getXIndex(events[i].x1);
            int v = getXIndex(events[i].x2);
            
            update(1, 0, X.size() - 1, u, v, events[i].type);
            double h = events[i+1].y - events[i].y;
            double width = tree[1].length;
            
            double stripArea = width * h;
            layerAreas.push_back(stripArea);
            totalArea += stripArea;
        }

        double target = totalArea / 2.0;
        double currentArea = 0;
        
        fill(tree.begin(), tree.end(), Node{0, 0.0}); 
        
        for (size_t i = 0; i < events.size() - 1; ++i) {
            int u = getXIndex(events[i].x1);
            int v = getXIndex(events[i].x2);
            
            update(1, 0, X.size() - 1, u, v, events[i].type);
            
            double h = events[i+1].y - events[i].y;
            double width = tree[1].length;
            double stripArea = width * h;
            
            if (currentArea + stripArea >= target) {
                double needed = target - currentArea;
                if (width == 0) return events[i].y; 
                return events[i].y + needed / width;
            }
            
            currentArea += stripArea;
        }

        return 0.0;
    }
};