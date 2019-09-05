//Topology sort
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> v[numCourses];
        for(auto &p: prerequisites) {
            v[p[0]].push_back(p[1]);
        }
        // check if there is a cycle 
        vector<bool> vis(numCourses, false);
        vector<bool> recur(numCourses, false);
        
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                if(cycle(v, vis, recur, i)) return false;
            }
        }
        return true;    
    }
    
    bool cycle(vector<int> *v, vector<bool> &vis, vector<bool> &recur, int idx) {
        if(!vis[idx]) {
            vis[idx] = true;
            recur[idx] = true;
            for(int x: v[idx]) {
                if(!vis[x] && cycle(v, vis, recur, x)) return true;
                else if(recur[x]) return true;
            }
        }
        recur[idx] = false;
        return false;
    }
};
