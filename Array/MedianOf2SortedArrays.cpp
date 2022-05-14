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
        int s1 = nums1.size(), s2 = nums2.size();
        
        if (s1 > s2) return findMedianSortedArrays(nums2, nums1);
        
        int start = 0, end = s1;
        
        while (start <= end) {
            int mid1 = (start + end) / 2;
            int mid2 = (s1 + s2 + 1) / 2 - mid1;
            
            int l1 = mid1 == 0 ? INT_MIN : nums1[mid1 - 1];
            int l2 = mid2 == 0 ? INT_MIN : nums2[mid2 - 1];
            int r1 = mid1 == s1 ? INT_MAX : nums1[mid1];
            int r2 = mid2 == s2 ? INT_MAX : nums2[mid2];
            
            if (l1 <= r2 && l2 <= r1) {
                if ((s1 + s2) & 1) return max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            } else if (l1 > r2) {
                end = mid1 - 1;
            } else if (l2 > r1) {
                start = mid1 + 1;
            }
        }
        
        return 0.0;
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
