class MedianFinder {
public:

    priority_queue<int> mx; //max heap
    priority_queue<int, vector<int>, greater<int>> mn; //min heap

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mx.empty() || mx.top() >= num) {
            mx.push(num);
        } else {
            mn.push(num);
        }

        if(abs((int)mx.size() - (int)mn.size()) > 1) {
            if(mx.size() > mn.size()) {
                while(mx.size() - mn.size() > 1) {
                    mn.push(mx.top());
                    mx.pop();
                }
            } 

            else if(mx.size() < mn.size()) {
                while(mn.size() - mx.size() > 1) {
                    mx.push(mn.top());
                    mn.pop();
                }
            }
        }
    }
    
    double findMedian() {
        
        if((mx.size() + mn.size()) % 2 != 0) {
            if(mx.size() > mn.size()) return mx.top();
            else return mn.top();
        }

        return (mx.top()+mn.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
