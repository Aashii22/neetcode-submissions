class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int> > right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.push(num);
        if(left.size()>right.size()){
            right.push(left.top());
            left.pop();
        }

        if(!left.empty() && !right.empty() && left.top()>right.top()){
            int a = left.top(), b = right.top();
            left.pop(); right.pop();
            left.push(b); right.push(a);
        }
    }
    
    double findMedian() {
        int n = (left.size()+right.size());

        if(n%2==0)
        return (double)(left.top() + right.top())/2;
        else
        return (double)(right.top());
    }
};
