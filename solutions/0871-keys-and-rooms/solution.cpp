class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();

        vector<bool> unlocked(n, false);
        unlocked[0] = true;

        queue<int> q;
        q.push(0);

        while(!q.empty()) {

            int x = q.front();
            q.pop();

            for(int key : rooms[x]) {
                if(unlocked[key]) continue;

                q.push(key);
                unlocked[key] = true;
            }

        }

        for(int i = 0; i < n; i++) {
            if(!unlocked[i]) return false;
        }
        
        return true;
    }
};
