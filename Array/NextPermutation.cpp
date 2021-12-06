/*

**************** Problem Description ****************

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.


    Example1 : 

    Input: nums = [1,2,3]

    Output: [1,3,2]


    Example2 : 

    Input: nums = [3,2,1]

    Output: [1,2,3]


    Example3 : 

    Input: nums = [1,1,5]

    Output: [1,5,1]


    Example4 : 

    Input: nums = [1]

    Output: [1]

*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Identify pivot
        // Pivot is the element just before the non-increasing (weakly decreasing) suffix
        bool found = false;
        int pivot;
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] > nums[i-1]) {
                found = true;
                pivot = i-1;
                break;
            }
        }

        // Entire array is in decreasing order, return sorted array
        if (!found) {
            sort(nums.begin(), nums.end());
            return;
        }

        // Find rightmost successor of pivot in suffix
        int mn = INT_MAX, idx;
        for (int i = pivot + 1; i < nums.size(); i++) {
            if (nums[i] > nums[pivot] && nums[i] <= mn) {
                mn = nums[i];
                idx = i;
            }
        }
        
        // Swap the pivot
        swap(nums[pivot], nums[idx]);
        
        // Reverse the suffix
        int i = pivot + 1;
        int j = nums.size() - 1;
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};

/*

**************** Logic ****************
If the array is in decreasing order, we cannot form a greater number by swapping as it is already max number possible.
Smallest next number can be formed if we swap numbers close to the rightmost end (Least Significant Bits).

1. Identify pivot. Pivot is the element just before the non-increasing (weakly decreasing) suffix

2. Find rightmost successor of pivot in suffix

3. Swap the pivot

4. Reverse the suffix as the suffix is in decreasing order and we have already increased the pivot value which is the higher significant bit.

*/
