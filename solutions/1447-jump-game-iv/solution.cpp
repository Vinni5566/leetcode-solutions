class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();

        if(n == 1) return 0;
        if(n == 2) return 1;

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        vector<int> vis(n, 0);

        return bfs(arr, vis, 0, n, mp);
    }

    int bfs(vector<int>& arr, vector<int>& vis, int index, int n, unordered_map<int, vector<int>>& mp) {

        queue<int> q;
        q.push(index);

        vis[index] = 1;

        int mn_stps = 0;

        while(!q.empty()) {

            int size = q.size();

            for(int i = 0; i < size; i++) {
                int idx = q.front();
                q.pop();
                
                if(idx == n-1) return mn_stps;

                int l = idx-1;
                int r = idx+1;

                if(l >= 0 && !vis[l]) {
                    q.push(l);
                    vis[l] = 1;
                }

                if(r < n && !vis[r]) {
                    q.push(r);
                    vis[r] = 1;
                }

                if(mp.count(arr[idx])) {
                    for(auto& p : mp[arr[idx]]) {
                        if(p != idx && !vis[p]) {
                            q.push(p);
                            vis[p] = 1;
                        }
                    }

                    mp.erase(arr[idx]);
                }  
            }

            mn_stps++;
        }

        return mn_stps;
    }
};
