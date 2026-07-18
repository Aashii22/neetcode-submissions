class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();

        vector<vector<int> > adj(num);
        vector<int> indeg(num, 0);
        for(int i=0; i<n; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }

        queue<int> q;
        for(int i=0; i<num; i++){
            if(indeg[i]==0)
            q.push(i);
        }

        int sz, tmp, total=0;
        while(!q.empty()){

            sz = q.size();
            total+=sz;
            while(sz--){
                tmp = q.front();
                q.pop();

                for(int x: adj[tmp]){
                    indeg[x]--;
                    if(indeg[x]==0)
                    q.push(x);
                }
            }
        }

        return total==num ? true : false;
    }
};
