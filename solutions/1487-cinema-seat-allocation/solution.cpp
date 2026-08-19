class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        int m = reservedSeats.size();

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < m; i++) {
            int r = reservedSeats[i][0];
            int s = reservedSeats[i][1];

            mp[r].push_back(s);
        }

        int res = 0;

        for(auto& p : mp) {

            vector<int> seats(10, 0);

            for(int x : p.second) {
                seats[x-1] = 1;
            }

            if(
                (seats[1] == 0 && seats[2] == 0 && seats[3] == 0 && seats[4] == 0) &&
                (seats[5] == 0 && seats[6] == 0 && seats[7] == 0 && seats[8] == 0)
            ) {
                res += 2;
            }

            else if(
                (seats[1] == 0 && seats[2] == 0 && seats[3] == 0 && seats[4] == 0) ||
                (seats[3] == 0 && seats[4] == 0 && seats[5] == 0 && seats[6] == 0) ||
                (seats[5] == 0 && seats[6] == 0 && seats[7] == 0 && seats[8] == 0) 
            ) {
                res += 1;
            }
            
        }

        res += (n-mp.size())*2;

        return res;

    }
};
