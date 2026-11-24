class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String> > group = new HashMap<>();
        char[] tmp;
        String sortedString;
        for(String s: strs){
            tmp = s.toCharArray();
            Arrays.sort(tmp);
            sortedString = new String(tmp);
            group.computeIfAbsent(sortedString, k->new ArrayList<>()).add(s);
        }

        List<List<String> > ans = new ArrayList<>();
        // group.forEach((key, value)->{
        //     ans.add(value);
        // });
        for(List<String> val: group.values()){
            ans.add(val);
        }
        return ans;
    }
}
