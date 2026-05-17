class Solution {
public:
    bool canReach(vector<int>& arr, int start) {

        int n = arr.size();

        queue<int> q;
        
        vector<int> visited(n, 0);

        if(bfs(arr, visited, start, n)) return true;
        
        return false;
        
    }

    bool bfs(vector<int>& arr, vector<int>& visited, int i, int n) {

        queue<int> q;
        q.push(i);
        visited[i] = 1;

        while(!q.empty()) {

            int idx = q.front();
            q.pop();

            if(arr[idx] == 0) return true;

            int l = idx-arr[idx];
            int r = idx+arr[idx];

            if(l >= 0 && !visited[l]) {
                q.push(l);
                visited[l] = 1;
            }

            if(r < n && !visited[r]) {
                q.push(r);
                visited[r] = 1;
            }
        }

        return false;
    }
};
