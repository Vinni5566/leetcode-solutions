class Solution {

public:
    int minJumps(vector<int>& nums) {

        int n = nums.size();

        int mx = *max_element(nums.begin(), nums.end());

        vector<int> spf(mx+1);
        
        for(int i = 0; i < mx+1; i++) {
            spf[i] = i; //assume every num is its own spf
        }

        for(int i = 2; i * i <= mx; i++) {
            if(spf[i] == i) {
                for(int j = i * i; j <= mx; j += i) {
                    if(spf[j] == j) spf[j] = i;
                }
            }
        }

        //key : p (prime number)
        //value: vector of indexes (where nums[index] % p == 0)
        vector<vector<int>> bucket(mx+1);
        
        for (int i = 0; i < n; i++) {
            int x = nums[i];

            while(x > 1) {
                int p = spf[x];

                while(x % p == 0) x /= p;

                bucket[p].push_back(i);
            }
        }

        //bfs
        vector<int> visited(n, 0);
        int minJumps = 0;

        queue<int> q;

        q.push(0);
        visited[0] = 1;

        while(!q.empty()) {

            int size = q.size();

            while(size--) {
                int idx = q.front();
                q.pop();

                if(idx == n-1) return minJumps;

                if(idx - 1 >= 0 && !visited[idx-1]) {
                    q.push(idx-1);
                    visited[idx-1] = 1;
                } 
                
                if(idx + 1 < n && !visited[idx+1]) {
                    q.push(idx+1);
                    visited[idx+1] = 1;
                } 

                if(nums[idx] > 1 && spf[nums[idx]] == nums[idx]) {
                    for(auto & index : bucket[nums[idx]]) {
                        if(!visited[index]) {
                            q.push(index);
                            visited[index] = 1;
                        }
                    }

                    bucket[nums[idx]].clear();
                }
            }

            minJumps++; 
        }

        return minJumps;

    }
    
};
