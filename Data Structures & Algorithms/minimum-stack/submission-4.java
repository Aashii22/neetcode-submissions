class MinStack {
    Deque<Long> stk;
    long currMin;
    public MinStack() {
        stk = new ArrayDeque<>();
        currMin = 0L;
    }
    
    public void push(int val) {
        if(stk.isEmpty()){
            currMin = (long)val;
        }
        long diff = (long)val - currMin;
        stk.push(diff);
        if(diff < 0)
        currMin = (long)val;
    }
    
    public void pop() {
        long diff = stk.pop();
        if(diff<0){
            currMin-=diff;
        }
    }
    
    public int top() {
        long diff = stk.peek();
        if(diff<0)
        return (int)currMin;
        else
        return (int)(diff + currMin);
    }
    
    public int getMin() {
        return (int)currMin;
    }
}
