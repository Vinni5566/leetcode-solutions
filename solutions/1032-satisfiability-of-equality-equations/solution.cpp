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
    bool equationsPossible(vector<string>& equations) {
        
        int n = equations.size();

        vector<int> parent(26);

        for(int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        vector<int> rank(26, 0);

        //do union of == cases
        for(string& s : equations) {

            char ch_0 = s[0];
            char ch_1 = s[1];
            char ch_3 = s[3];

            int parent_0 = find(ch_0-'a', parent);
            int parent_3 = find(ch_3-'a', parent);

            if(ch_1 == '=') {
                Union(parent_0, parent_3, parent, rank);
            }
        }

        //find and check != cases
        for(string& s : equations) {

            char ch_0 = s[0];
            char ch_1 = s[1];
            char ch_3 = s[3];

            int parent_0 = find(ch_0-'a', parent);
            int parent_3 = find(ch_3-'a', parent);

            if(ch_1 == '!') {
                if(parent_0 == parent_3) return false;
            }
        }

        return true;
    }
};
