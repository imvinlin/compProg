class Solution {
private:
    unordered_map<int, vector<int>> adj;
    set<int> visit;
    set<int> cycle;
    vector<int> res;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto& c : prerequisites) adj[c[0]].push_back(c[1]);
        for(int i = 0; i < numCourses; i++){
            if(!dfs(i)) return vector<int>();
        }
        return res;
    }
    bool dfs(int node){
        if(cycle.find(node) != cycle.end()) return false;
        if(visit.find(node) != visit.end()) return true;
        cycle.insert(node);
        for(auto& preq : adj[node]) if(!dfs(preq)) return false;
        cycle.erase(node);
        visit.insert(node);
        res.push_back(node);
        return true;
    }
};
