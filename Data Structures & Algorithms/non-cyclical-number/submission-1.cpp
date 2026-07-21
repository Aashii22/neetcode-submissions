class Solution {
public:
    int digitSum(int n){
        int sum = 0;
        while(n>0){
            sum+=pow(n%10, 2);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        map<int, bool> mp;
        mp.clear();

        while(n!=1){
            if(mp.find(n)!=mp.end())
            return false;

            mp[n]=true;
            n = digitSum(n);
        }

        return true;
    }
};
