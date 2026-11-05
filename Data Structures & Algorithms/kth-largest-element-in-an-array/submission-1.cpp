class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap of size k
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);

            // Keep the heap size at most k
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // The root of the min-heap is the kth largest element
        return minHeap.top();
    }
};