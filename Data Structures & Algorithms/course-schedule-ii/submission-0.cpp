class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > adj(numCourses);
        vector<int> indegree(numCourses, 0);

        int edges = prerequisites.size();

        for(int i=0; i<edges; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        vector<int> ans;
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0)
            q.push(i);
        }

        int sz=0, curr;
        while(!q.empty()){
            sz = q.size();
            while(sz--){
                curr = q.front();
                q.pop();

                ans.push_back(curr);
                for(int x: adj[curr]){
                    indegree[x]--;
                    if(indegree[x]==0)
                    q.push(x);
                }
            }
        }

        if(ans.size()==numCourses)
        return ans;
        else
        return {};
    }
};
