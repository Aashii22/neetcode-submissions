class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int t = tasks.size();

        if(n==0)
        return t;

        vector<int> freq(26);
        for(int x: tasks){
            freq[x-'A']++;
        }

        int cnt=0, mx=0;
        for(int i=0; i<26; i++){
            if(mx < freq[i]){
                mx = freq[i];
                cnt = 1;
            }
            else if(mx == freq[i]){
                cnt++;
            }
        }

        return max((int)t, (n+1)*(mx-1) + cnt);
    }
};
