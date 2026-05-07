class Solution {

private:
    
    int find(int i, vector<int>& parent) {

        if(i == parent[i]) return i;

        return parent[i] = find(parent[i], parent);
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank) {

        int parent_x = find(x, parent);
        int parent_y = find(y, parent);

        if(rank[parent_x] > rank[parent_y]) {
            parent[parent_y] = parent_x;
        }

        else if(rank[parent_x] < rank[parent_y]) {
            parent[parent_x] = parent_y;
        }

        else {
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<int> parent(1001);

        for(int i = 0; i < 1001; i++) {
            parent[i] = i;
        }

        vector<int> rank(1001, 0);

        int res_u = -1;
        int res_v = -1;

        for(auto& edge : edges) {

            int u = edge[0];
            int v = edge[1];

            int parent_u = find(u, parent);
            int parent_v = find(v, parent);

            if(parent_u == parent_v) {
                res_u = u;
                res_v = v;
            } else {
                Union(u, v, parent, rank);
            }
        }

        return {res_u, res_v};
    }
};
