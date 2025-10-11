Given an integer array `nums` and an integer `k`, return _the_ `kth` _largest element in the array_.

Note that it is the `kth` largest element in the sorted order, not the `kth` distinct element.

Link : [215. Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)

```cpp
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < nums.size(); i++) {
        pq.push(nums[i]);
        
        if (pq.size() > k) {
            pq.pop();
        }
    }
    
    int ret = pq.top();
    return ret;
}
```

### TC : O(N* log K)     SC : O(K)
