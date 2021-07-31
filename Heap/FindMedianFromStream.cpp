/*

**************** Problem Description ****************
The median is the middle value in an ordered integer list. If the size of the list is even,
there is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.


    Example : 1

    Input:
    ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
    [[], [1], [2], [], [3], []]

    Output:
    [null, null, null, 1.5, null, 2.0]

    Explanation:
    MedianFinder medianFinder = new MedianFinder();
    medianFinder.addNum(1);    // arr = [1]
    medianFinder.addNum(2);    // arr = [1, 2]
    medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
    medianFinder.addNum(3);    // arr[1, 2, 3]
    medianFinder.findMedian(); // return 2.0

*/


class MedianFinder {
public:
    priority_queue<int> sm;
    priority_queue<int, vector<int>, greater<int>> lg;
    
    void balance() {
        if ((int)(sm.size() - lg.size()) > 1) {
            int top = sm.top();
            sm.pop();
            lg.push(top);
        }
        
        if ((int)(lg.size() - sm.size()) > 1) {
            int top = lg.top();
            lg.pop();
            sm.push(top);
        }
    }
    
    void addNum(int num) {
        if (sm.empty() && lg.empty()) {
            sm.push(num);
            return;
        }
        
        double currMedian = findMedian();
        
        if (num > currMedian) lg.push(num);
        else sm.push(num);
        
        balance();
    }
    
    double findMedian() {
        if (sm.size() > lg.size()) return (double)sm.top();
        
        if (lg.size() > sm.size()) return (double)lg.top();
        
        return (double)(sm.top() + lg.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/*

**************** Logic ****************
We can use a max heap on left side to represent elements that are less than effective median,
and a min heap on right side to represent elements that are greater than effective median.

After processing an incoming element, the number of elements in heaps differ utmost by 1 element.
When both heaps contain same number of elements, we pick average of heaps root data as effective median.
When the heaps are not balanced, we select effective median from the root of heap containing more elements.

*/
