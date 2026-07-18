class Solution {
public:
    bool isAlpha(char a){
        if((a>='a' && a<='z') || (a>='A' && a<='Z') || (a>='0' && a<='9'))
        return true;
        else
        return false;
    }
    bool isPalindrome(string s) {
        int n = s.length();

        int l=0, r=n-1;
        while(l<r){
            if(l<r && !isAlpha(s[l]))
            l++;
            else if(l<r && !isAlpha(s[r]))
            r--;
            else if(tolower(s[l])!=tolower(s[r]))
            return false;
            else
            l++, r--;
        }
        return true;
    }
};
