class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        set<pair<int, int>> obs;

        for(const auto& obstacle : obstacles) {
            obs.insert({obstacle[0], obstacle[1]});
        }

        int n = commands.size();

        int maxDist = 0;

        bool right = false;
        bool left = false;
        bool up = true;
        bool down = false;

        int x = 0;
        int y = 0;

        for(int i = 0; i < n; i++) {

            if(commands[i] == -1) {
                if(up) { up = false; right = true; }
                else if(right) { right = false; down = true; }
                else if(down) { down = false; left = true; }
                else if(left) { left = false; up = true; }
            } 

            else if(commands[i] == -2) {
                if(up) { up = false; left = true; }
                else if(left) { left = false; down = true; }
                else if(down) { down = false; right = true; }
                else if(right) { right = false; up = true; }
            }

            else {

                for(int j = 0; j < commands[i]; j++) {
                    int nextX = x;
                    int nextY = y;

                    if(up) nextY++;
                    else if(down) nextY--;
                    else if(right) nextX++;
                    else if(left) nextX--;

                    if(obs.count({nextX, nextY})) break;

                    x = nextX;
                    y = nextY;

                    maxDist = max(maxDist, x*x + y*y);

                }
            }
        }

        return maxDist;
        
    }
};
