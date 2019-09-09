class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> res;
        vector<int> degree(numCourses, 0);
        for(auto &p : prerequisites){
            adj[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(degree[i] == 0){
                q.push(i);
                res.push_back(i);
            }
        }
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            numCourses--;
            for(auto next : adj[curr]){
                if(--degree[next] == 0){
                    res.push_back(next);
                    q.push(next);
                }
            }
        }
        if(numCourses == 0) return res;
        else return (vector<int>());
    }
};
