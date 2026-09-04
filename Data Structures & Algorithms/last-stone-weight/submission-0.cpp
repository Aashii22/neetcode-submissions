class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();

        priority_queue<int> pq;
        for(auto x: stones){
            pq.push(x);
        }

        int x, y;
        while(pq.size()>1){
            x = pq.top(); pq.pop();
            y = pq.top(); pq.pop();

            if(x>y){
                pq.push(x-y);
            }
            else if(x<y){
                pq.push(y-x);
            }
        }

        if(pq.empty())
        return 0;
        else
        return pq.top();
    }
};
