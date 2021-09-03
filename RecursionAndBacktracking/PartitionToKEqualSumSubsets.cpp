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
    bool canPartition(vector<int>& nums, vector<int>& visited, int k, int start, int sum, int target) {
        if (sum > target) return false;
        
        if (k == 1) return true;
        
        if (sum == target) return canPartition(nums, visited, k - 1, 0, 0, target);
        
        for (int i = start; i < nums.size(); i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
            
                if (canPartition(nums, visited, k, i+1, sum + nums[i], target)) return true;

                visited[i] = 0;
            }
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (auto n : nums) sum += n;
        
        if (sum % k != 0) return false;
        
        vector<int> visited(nums.size(), 0);
        
        return canPartition(nums, visited, k, 0, 0, sum / k);
    }
};

/*

**************** Logic ****************
We can figure out what target each subset must sum to. Assume sum is the sum of nums[].
The dfs process is to find a subset of nums[] which sum equals to target(sum/k). We use an array visited[] to record which element in nums[] is used.
Each time when we get a cur_sum = sum/k, we will start from position 0 in nums[] to look up the elements that are not used yet and find another cur_sum = sum/k.

*/
