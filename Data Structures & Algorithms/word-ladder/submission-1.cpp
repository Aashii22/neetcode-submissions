class Solution {
public:
    int cnt;
    bool hasEdge(string a, string b){
        cnt = 0;
        for(int i=0; i<a.length(); i++){
            if(a[i]==b[i])
            cnt++;
        }
        return cnt==a.length()-1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto it = find(wordList.begin(), wordList.end(), endWord);
        if(it==wordList.end())
        return 0;

        int tgt_idx = it - wordList.begin();

        int n = wordList.size();

        vector<vector<int> > adj(n+1);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(hasEdge(wordList[i], wordList[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
            if(hasEdge(wordList[i], beginWord)){
                adj[i].push_back(n);
                adj[n].push_back(i);
            }
        }

        queue<int> q;
        q.push(n);

        int sz=0, curr, ans=1;
        vector<bool> vis(n+1, false);
        vis[n] = true;
        while(!q.empty()){
            sz = q.size();
            while(sz--){
                curr = q.front();
                q.pop();

                if(tgt_idx == curr)
                return ans;

                for(int x: adj[curr]){
                    if(!vis[x]){
                        vis[x]=true;
                        q.push(x);
                    }
                }
            }

            ans++;
        }

        return 0;
    }
};
