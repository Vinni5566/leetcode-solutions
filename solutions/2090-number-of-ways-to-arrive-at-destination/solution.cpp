class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const long long MOD = 1e9 + 7;

        // Build adjacency list: adj[node] = vector of {neighbor, travel_time}
        vector<vector<pair<int, long long>>> adj(n);
        for(auto &road : roads) {
            int u = road[0];
            int v = road[1];
            long long travelTime = road[2];

            adj[u].push_back({v, travelTime});
            adj[v].push_back({u, travelTime}); // undirected graph
        }

        // Initialize shortest travel times from node 0
        vector<long long> shortestTime(n, LLONG_MAX);
        shortestTime[0] = 0;

        // ways[i] = number of shortest paths to reach node i
        vector<long long> ways(n, 0);
        ways[0] = 1;

        // Min-heap: {time to reach node, node index}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minHeap;
        minHeap.push({0, 0}); // start from node 0 with 0 time

        while(!minHeap.empty()) {
            auto [currentTime, currentNode] = minHeap.top();
            minHeap.pop();

            if(currentTime > shortestTime[currentNode]) continue; // stale pair

            // Explore neighbors
            for(auto &neighborPair : adj[currentNode]) {
                int neighborNode = neighborPair.first;
                long long edgeTime = neighborPair.second;

                long long newTime = currentTime + edgeTime;

                // found the shortes path
                if(newTime < shortestTime[neighborNode]) {
                    shortestTime[neighborNode] = shortestTime[currentNode] + edgeTime;
                    minHeap.push({shortestTime[neighborNode], neighborNode});
                    ways[neighborNode] = ways[currentNode];
                } 
                
                //found another shortest path
                else if(newTime == shortestTime[neighborNode]) {
                    ways[neighborNode] = (ways[neighborNode] + ways[currentNode]) % MOD;
                }
            }
        }

        return ways[n-1]; // numsber of ways to reach destination node in shortest time
  
    }
};
