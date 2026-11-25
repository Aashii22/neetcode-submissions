class Solution {

    public String encode(List<String> strs) {
        StringBuilder res = new StringBuilder();
        for(String s: strs){
            res.append(s.length()).append('#').append(s);
        }
        return res.toString();
    }

    public List<String> decode(String str) {
        int n = str.length();
        List<String> res = new ArrayList<>();

        int i=0, j, len;
        while(i<n){
            j = i;
            while(str.charAt(j)!='#')
            j++;

            len = Integer.parseInt(str.substring(i, j));

            i = j+1;
            j = i+len;
            res.add(str.substring(i, j));
            i=j;
        }

        return res;
    }
}
