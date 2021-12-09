/*

**************** Problem Description ****************
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.


    Example 1 : 

    Input: nums = [2,0,2,1,1,0]

    Output: [0,0,1,1,2,2]


    Example 2 : 

    Input: nums = [2,0,1]
    
    Output: [0,1,2]


    Example 3 : 

    Input: nums = [0]
    
    Output: [0]


    Example 4 : 

    Input: nums = [1]

    Output: [1]

*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = nums.size() - 1;
        
        while (white <= blue) {
            if (nums[white] == 0) {
                swap(nums[white], nums[red]);
                red++;
                white++;
            } else if (nums[white] == 1) {
                white++;
            } else if (nums[white] == 2) {
                swap(nums[white], nums[blue]);
                blue--;
            }
        }
    }
};

/*

**************** Logic ****************
This is a dutch partitioning problem. We are classifying the array into four groups: red, white, unclassified, and blue.
Initially we group all elements into unclassified. We iterate from the beginning as long as the white pointer is less than the blue pointer.

If the white pointer is red (nums[white] == 0), we swap with the red pointer and move both white and red pointer forward.
If the pointer is white (nums[white] == 1), the element is already in correct place, so we don't have to swap, just move the white pointer forward.
If the white pointer is blue, we swap with the latest unclassified element.

*/
