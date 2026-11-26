class Solution {
    public boolean isValid(String s) {
        Deque<Character> stack = new ArrayDeque<>();
        for(char x: s.toCharArray()){
            if(x=='(' || x=='{' || x=='[')
            stack.push(x);
            else{
                if(!stack.isEmpty()){
                    if((x==')' && stack.peek()=='(') || (x=='}' && stack.peek()=='{') || (x==']' && stack.peek()=='['))
                    stack.poll();
                    else
                    return false;
                }
                else
                return false;
            }
        }

        if(!stack.isEmpty())
        return false;

        return true;

    }
}
