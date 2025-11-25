class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        vector<int> inDegree(numCourses, 0);
        
        for(int i = 0; i < numCourses; i++) {
            for(int j = 0; j < graph[i].size(); j++) {
                inDegree[graph[i][j]]++;
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) q.push(i);
        }
        
        int count = 0;  //var to count processed nodes
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            count++;
            
            for(int v : graph[u]) {
                inDegree[v] -= 1;
                if(inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return count == numCourses;
    }

    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);

        for(int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        return graph;
    }

};
