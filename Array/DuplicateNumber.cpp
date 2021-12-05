/*

**************** Problem Description ****************

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.


    Example1 : 

    Input: nums = [1,3,4,2,2]

    Output: 2


    Example2 : 

    Input: nums = [3,1,3,4,2]
    
    Output: 3


    Example3 : 

    Input: nums = [1,1]
    
    Output: 1


    Example4 : 

    Input: nums = [1,1,2]

    Output: 1

*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size() - 1;
        
        while (low < high) {
            int mid = (low + high) / 2;
            
            int count = 0;
            for (int num : nums) {
                if (num <= mid) count++;
            }
            
            if (count > mid) high = mid;
            else low = mid + 1;
        }
        
        return low;
    }
};

/*

**************** Logic ****************
At first the search space is numbers between 1 to n.
Each time we select a number mid (which is the one in the middle) and count all the numbers equal to or less than mid.
If the count is more than mid, the search space will be [1 to mid] otherwise [mid+1 to n]. I do this until search space is only one number.

Let's say n=10 and I select mid=5. Then I count all the numbers in the array which are less than equal mid.
If the there are more than 5 numbers that are less than or equal to 5, then by Pigeonhole Principle, one of them has occurred more than once.
So I shrink the search space from [1 to 10] to [1 to 5]. Otherwise the duplicate number is in the second half so for the next step the search space would be [6 to 10].

*/
