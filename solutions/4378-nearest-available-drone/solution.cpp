class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        
        int tx = target[0];
        int ty = target[1];

        int idx = -1;
        int minDist = INT_MAX;

        for(int i = 0; i < drones.size(); i++) {
            int x = drones[i][0];
            int y = drones[i][1];
            int r = drones[i][2]; //range

            int dist = abs(tx - x) + abs(ty - y);

            if(dist <= r) {
                if(dist < minDist) {
                    idx = i;
                    minDist = dist;
                }
            } 
        }

        return idx;
    }
};
