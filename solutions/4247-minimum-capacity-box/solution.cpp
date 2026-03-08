class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {

        int n = capacity.size();

        int index = -1;
        int size = capacity[0];

        for(int i = 0; i < n; i++) {
            if(capacity[i] >= itemSize) {
                if(index == -1) {
                    index = i;
                    size = capacity[i];
                    continue;
                } else {
                    if(capacity[i] < size) {
                        index = i;
                        size = capacity[i];
                    } else if(capacity[i] == size) {
                        index = min(i, index);
                    }
                }
            }
        }

        return index;
        
    }
};
