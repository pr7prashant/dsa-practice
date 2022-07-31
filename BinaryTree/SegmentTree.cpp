/*

**************** Problem Description ****************

Given an integer array nums, handle multiple queries of the following types:

Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
    
    
    Example : 1
    
    Input:
    ["NumArray", "sumRange", "update", "sumRange"]
    [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]

    Output:
    [null, 9, null, 8]

    Explanation:
    NumArray numArray = new NumArray([1, 3, 5]);
    numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
    numArray.update(1, 2);   // nums = [1, 2, 5]
    numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8

*/

class NumArray {
public:
    int size;
    vector<int> tree;
    
    NumArray(vector<int>& nums) {
        size = nums.size();
        tree = vector<int>(size * 4, 0);
        buildSegmentTree(nums, 0, 0, size - 1);
    }
    
    void buildSegmentTree(vector<int>& nums, int idx, int start, int end) {
        if (start == end) {
            tree[idx] = nums[start];
            return;
        }
        
        int mid = (start + end) / 2;
        buildSegmentTree(nums, 2*idx+1, start, mid);
        buildSegmentTree(nums, 2*idx+2, mid+1, end);
        tree[idx] = tree[2*idx+1] + tree[2*idx+2];
    }
    
    int query(int idx, int start, int end, int left, int right) {
        if (start >= left && end <= right) return tree[idx];
        if ((start < left && end < left) || (start > right && end > right)) return 0;
        
        int mid = (start + end) / 2;
        int l = query(2*idx+1, start, mid, left, right);
        int r = query(2*idx+2, mid+1, end, left, right);
        return l + r;
    }
    
    int updateNode(int idx, int target, int val, int start, int end) {
        if (start == end) {
            if (start != target) return 0;
            int old = tree[idx];
            tree[idx] = val;
            return val - old;
        }
        if (end < target || start > target) return 0;
        
        int mid = (start + end) / 2;
        int l = updateNode(2*idx+1, target, val, start, mid);
        int r = updateNode(2*idx+2, target, val, mid+1, end);
        int old = tree[idx];
        tree[idx] += l + r;
        return tree[idx] - old;
    }
    
    void update(int index, int val) {
        updateNode(0, index, val, 0, size - 1);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, size-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
