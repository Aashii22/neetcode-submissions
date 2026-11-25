class Solution {
    public int longestConsecutive(int[] nums) {
        int n = nums.length;

        Map<Integer, Integer> track = new HashMap<>();
        int ans = 0;
        for(int x: nums){
            if(track.containsKey(x))
            continue;

            int left = track.getOrDefault(x-1, 0);
            int right = track.getOrDefault(x+1, 0);

            track.put(x-left, left+right+1);
            track.put(x+right, left+right+1);
            
            track.put(x, left+right+1);
            ans = Math.max(ans, track.get(x));
        }

        return ans;
    }
}
