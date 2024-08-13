class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> mini;
    priority_queue<int> maxi;
    MedianFinder()
    {}
    
    void addNum(int num) {
        maxi.push(num);

        if(!mini.empty() && !maxi.empty() && maxi.top()>mini.top())
        {
            mini.push(maxi.top());
            maxi.pop();
        }

        if(maxi.size() > mini.size()+1)
        {
            mini.push(maxi.top());
            maxi.pop();
        }

        if(mini.size()>maxi.size()+1)
        {
            maxi.push(mini.top());
            mini.pop();
        }
    }
    
    double findMedian() {
        if(mini.size()>maxi.size())
            return mini.top();
        if(maxi.size()>mini.size())
            return maxi.top();
        
        else return (mini.top()+maxi.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */