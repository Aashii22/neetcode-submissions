class Twitter {
    private int time;
    Map<Integer, Set<Integer> > followMap;
    Map<Integer, List<int[]> > tweetMap;
    public Twitter() {
        this.time = 0;
        this.followMap = new HashMap<>();
        this.tweetMap = new HashMap<>();
    }
    
    public void postTweet(int userId, int tweetId) {
        tweetMap.putIfAbsent(userId, new ArrayList<>());
        tweetMap.get(userId).add(new int[]{time++, tweetId});
    }
    
    public List<Integer> getNewsFeed(int userId) {
        List<int[]> feed = new ArrayList<>(
            tweetMap.getOrDefault(userId, new ArrayList<>())
        );

        for(int followeeId: followMap.getOrDefault(userId, new HashSet<>())) {
            feed.addAll(tweetMap.getOrDefault(followeeId, new ArrayList<>()));
        }

        feed.sort((a, b) -> b[0] - a[0]);
        List<Integer> ans = new ArrayList<>();
        for(int i=0; i<Math.min(10, feed.size()); i++){
            ans.add(feed.get(i)[1]);
        }
        return ans;
    }
    
    public void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            followMap.putIfAbsent(followerId, new HashSet<>());
        }
        followMap.get(followerId).add(followeeId);
    }
    
    public void unfollow(int followerId, int followeeId) {
        followMap.getOrDefault(followerId, new HashSet<>()).remove(followeeId);
    }
}
