class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.length(), n = t.length();

        if(m!=n)
        return false;

        map<char, int> mp;
        for(char x: s){
            mp[x]++;
        }

        for(char x: t){
            if(mp[x]<=0)
            return false;

            mp[x]--;
        }

        return true;
    }
};
