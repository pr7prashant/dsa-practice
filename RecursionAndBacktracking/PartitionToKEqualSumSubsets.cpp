/*

**************** Problem Description ****************

Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.


  Example 1 : 
  
  Input: nums = [4,3,2,3,5,2,1], k = 4
  
  Output: true
  
  Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
  
  
  Example 2 : 
  
  Input: nums = [1,2,3,4], k = 3
  
  Output: false
  
*/

class Solution {
public:
    bool solve(vector<int>& nums, int subsetSum[], bool visited[], int k, int target, int start, int bucket) {
        if (k == 1) return true;
        if (start == nums.size()) return false;
        if (subsetSum[bucket] == target) return solve(nums, subsetSum, visited, k-1, target, 0, bucket + 1);
        
        for (int i = start; i < nums.size(); i++) {
            if (!visited[i]) {
                int temp = subsetSum[bucket] + nums[i];
                if (temp > target) continue;
                visited[i] = true;
                subsetSum[bucket] += nums[i];
                if (solve(nums, subsetSum, visited, k, target, i+1, bucket)) return true;
                subsetSum[bucket] -= nums[i];
                visited[i] = false;
            }
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int n : nums) sum += n;
        if (sum % k != 0) return false;
        
        int n = nums.size();
        bool visited[n];
        int subsetSum[k];
        for (int i = 0; i < k; i++) subsetSum[i] = 0;
        for (int i = 0; i < n; i++) visited[i] = false;
        
        return solve(nums, subsetSum, visited, k, sum/k, 0, 0);
    }
};

/*

**************** Logic ****************
We can figure out what target each subset must sum to. Assume sum is the sum of nums[].
Create k bucket. Recursively try to fill all the buckets using nums[].

*/
