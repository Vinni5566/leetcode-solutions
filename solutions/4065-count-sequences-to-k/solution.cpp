class Solution {
public:
    int countSequences(vector<int>& nums, long long k) {

        vector<tuple<int,int,int>> factors;

        for(int num : nums) {

            int x=0;
            int y=0;
            int z=0;

            while(num % 2 == 0) { 
                num/=2; 
                x++; 
            }

            while(num % 3 == 0) { 
                num/=3; 
                y++; 
            }

            while(num % 5 == 0) { 
                num/=5; 
                z++; 
            }

            factors.push_back({x,y,z});
        }

        int k_X=0;
        int k_Y=0;
        int k_Z=0;

        while(k % 2 == 0) { 
            k/=2; 
            k_X++; 
        }

        while(k % 3 == 0) { 
            k/=3; 
            k_Y++; 
        }

        while(k % 5 == 0) { 
            k/=5; 
            k_Z++; 
        }

        //k contains factors other than 2, 3 or 5
        if(k != 1) return 0;

        map<tuple<int,int,int>, long long> dp;
        dp[{0, 0, 0}] = 1;

        for(auto& [dx, dy, dz] : factors) {

            map<tuple<int,int,int>, long long> new_dp;

            for(auto& [state, count] : dp) {

                auto [currX, currY, currZ] = state;

                tuple<int, int ,int> multiply = {currX+dx, currY+dy, currZ+dz};
                new_dp[multiply] += count;

                tuple<int, int ,int> divide = {currX-dx, currY-dy, currZ-dz};
                new_dp[divide] += count;

                tuple<int, int ,int> leave = {currX, currY, currZ};
                new_dp[leave] += count;
            }

            dp = move(new_dp);
            
        }

        tuple<int,int,int> target = {k_X, k_Y, k_Z};

        return dp.count(target) ? dp[target] : 0;
        
    }
};
