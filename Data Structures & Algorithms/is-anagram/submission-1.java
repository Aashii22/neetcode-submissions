class Solution {
    public boolean isAnagram(String s, String t) {
        int m = s.length(), n = t.length();
        if(m!=n)
        return false;

        Map<Character, Integer> mp = new HashMap<>();
        for(char x: s.toCharArray()){
            mp.put(x, mp.getOrDefault(x, 0)+1);
        }

        for(char x: t.toCharArray()){
            if(mp.getOrDefault(x, 0)==0)
            return false;

            mp.put(x, mp.get(x)-1);
        }

        return true;
    }
}
