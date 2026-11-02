#include <queue>
#include <vector>
using namespace std;

class KthLargest {
private:
    int k;
    // Min-heap: smallest element is at the top
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        
        for (int num : nums) {
            add(num);               // reuse the add logic
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        
        // Keep only the k largest elements
        if (minHeap.size() > k) {
            minHeap.pop();          // remove the smallest
        }
        
        return minHeap.top();       // the smallest of the k largest = kth largest
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */