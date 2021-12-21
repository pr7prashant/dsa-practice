/*

**************** Problem Description ****************

In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket.
Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.


    Example 1:

    Input: position = [1,2,3,4,7], m = 3

    Output: 3

    Explanation:
    Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6].
    The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.


    Example 2:

    Input: position = [5,4,3,2,1,1000000000], m = 2

    Output: 999999999

    Explanation: We can use baskets 1 and 1000000000.

*/

class Solution {
public:
    bool isValidGap(vector<int>& position, int gap, int m) {
        m--;
        int prev = 0;
        for (int i = 1; i < position.size(); i++) {
            if (m == 0) return true;
            
            if (position[i] >= position[prev] + gap) {
                prev = i;
                m--;
            }
        }

        return m == 0;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int start = 1, end = position.back() - position.front(), ans = 0;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            if (isValidGap(position, mid, m)) {
                ans = mid;
                start = mid + 1;
            }
            else end = mid - 1;
        }
        
        return ans;
    }
};

/*

**************** Logic ****************
We need to maximise the minimum gap between two baskets.
Let gap can be in range 1 to arr[last] - arr[first].
Binary search on this range to find the maximum gap possible.

*/
