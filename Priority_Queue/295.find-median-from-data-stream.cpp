/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 * 
 * Learnings: 
 * 1. Non-Intutive Problem of priority_queue and a bit
 * famous one.
 * 
 */

// @lc code=start
class MedianFinder {
public:

    struct comp {
        bool operator()(const int &a, const int &b) {
            return a > b;
        }
    };

    priority_queue<int, vector<int>> max_heap;
    priority_queue<int, vector<int>, comp> min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (max_heap.size() == 0 && min_heap.size() == 0) {
            max_heap.push(num);
            return;
        }
        if(min_heap.size() == 0) {
            if (num >= max_heap.top()) {
                min_heap.push(num);
            } else {
                int valueToBeMoved = max_heap.top();
                max_heap.pop();
                min_heap.push(valueToBeMoved);
                max_heap.push(num);
            }
            return;
        }
        if (min_heap.size() > max_heap.size() && 
            num <= min_heap.top() && 
            max_heap.size() == 0) {
            int valueToBeMoved = min_heap.top();
            min_heap.pop();
            max_heap.push(valueToBeMoved);
            min_heap.push(num);
            return;
        }
        bool pushInMax = false;
        bool pushInMin = false;
        if (num <= max_heap.top()) {
            pushInMax = true;
        } else if (num >= min_heap.top()) {
            pushInMin = true;
        } else if (num > max_heap.top() && num < min_heap.top()) {
            if (min_heap.size() > max_heap.size()) {
                pushInMax = true;
            } else {
                pushInMin = true;
            }
        }
        if (min_heap.size() == max_heap.size()) {
            if (pushInMin) min_heap.push(num);
            else max_heap.push(num);
        } else if (min_heap.size() > max_heap.size()) {
            if (pushInMin) {
                int valueToBeMoved = min_heap.top();
                min_heap.pop();
                max_heap.push(valueToBeMoved);
                min_heap.push(num);
            } else {
                max_heap.push(num);
            }
        } else {
            if (pushInMax) {
                int valueToBeMoved = max_heap.top();
                max_heap.pop();
                min_heap.push(valueToBeMoved);
                max_heap.push(num);
            } else {
                min_heap.push(num);
            }
        }
        return;
    }
    
    double findMedian() {
        if (min_heap.size() == 0 && max_heap.size() == 0) {
            return 0.0;
        } 
        if (min_heap.size() == 0) {
            return (double) max_heap.top();
        }
        if (max_heap.size() == 0) {
            return (double) min_heap.top();
        }
        if (min_heap.size() == max_heap.size()) {
            return (double)(((double)min_heap.top() + (double)max_heap.top())/2);
        } else if (min_heap.size() > max_heap.size()) {
            return (double) min_heap.top();
        } else {
            return (double) max_heap.top();
        }
        return 0.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

