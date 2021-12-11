/*

**************** Problem Description ****************
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).


    Example 1 : 

    Input: nums1 = [1,3], nums2 = [2]

    Output: 2.00000

    Explanation: merged array = [1,2,3] and median is 2.


    Example 2 : 

    Input: nums1 = [1,2], nums2 = [3,4]

    Output: 2.50000
    
    Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


    Example 3 : 

    Input: nums1 = [0,0], nums2 = [0,0]
    
    Output: 0.00000


    Example 4 : 

    Input: nums1 = [], nums2 = [1]
    
    Output: 1.00000


    Example 5 : 

    Input: nums1 = [2], nums2 = []

    Output: 2.00000

*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        
        if (len1 > len2) return findMedianSortedArrays(nums2, nums1);
        
        int start = 0, end = len1;
        
        while (start <= end) {
            // X is nums1 and Y is nums2
            int partitionX = (start + end) / 2;
            int partitionY = (len1 + len2 + 1) / 2 - partitionX;
            
            int leftXMax = partitionX - 1 < 0 ? INT_MIN : nums1[partitionX - 1];
            int rightXMin = partitionX >= len1 ? INT_MAX : nums1[partitionX];
            
            int leftYMax = partitionY - 1 < 0 ? INT_MIN : nums2[partitionY - 1];
            int rightYMin = partitionY >= len2 ? INT_MAX : nums2[partitionY];
            
            if (leftYMax <= rightXMin && leftXMax <= rightYMin) {
                if ((len1 + len2) % 2 == 0) {
                    return (double)(max(leftXMax, leftYMax) + min(rightXMin, rightYMin)) / 2;
                }
                
                return max(leftXMax, leftYMax);
            } else if (leftXMax > rightYMin) {
                end = partitionX - 1;
            } else {
                start = partitionX + 1;
            }
        }
        
        return -1;
    }
};

/*

**************** Logic ****************
Brute Force: O(len1 + len2) space and time
Merge the 2 sorted arrays into a third sorted array and return the middle element.

Binary Search: O(log(min(len1, len2))) time and O(1) space
If we cut the sorted array to two halves of EQUAL LENGTHS, then median is the AVERAGE OF Max(lower_half) and Min(upper_half), i.e. the two numbers immediately next to the cut.

      left_part          |        right_part
A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]

If we can ensure:

1) len(left_part) == len(right_part)
2) max(left_part) <= min(right_part)

Then we divide all elements in {A, B} into two parts with equal length, and one part is always greater than the other.
Then median = (max(left_part) + min(right_part))/2, if total length is even.
Then median = max(left_part), if total length is odd.

*/
