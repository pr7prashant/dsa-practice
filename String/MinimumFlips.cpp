/*

**************** Problem Description ****************

You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:

Type-1: Remove the character at the start of the string s and append it to the end of the string.
Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.
Return the minimum number of type-2 operations you need to perform such that s becomes alternating.

The string is called alternating if no two adjacent characters are equal.

For example, the strings "010" and "1010" are alternating, while the string "0100" is not.


    Example : 1
        
    Input: s = "111000"

    Output: 2

    Explanation:
    Use the first operation two times to make s = "100011".
    Then, use the second operation on the third and sixth elements to make s = "101010".


    Example : 2
        
    Input: s = "010"

    Output: 0
    
    Explanation: The string is already alternating.


    Example : 3
        
    Input: s = "1110"

    Output: 1

    Explanation: Use the second operation on the second element to make s = "1010".

*/

class Solution {
public:
    int minFlips(string s) {
        // Pattern 1 - 101010...
        // Flips required = count 0's at even and 1's at odd places
        // Pattern 2 - 010101...
        // Flips required = count 1's at even and 0's at odd places
        
        // cnt[0][0] = number of '0' in even positions
        // cnt[0][1] = number of '0' in odd  positions
        // cnt[1][0] = number of '1' in even positions
        // cnt[1][1] = number of '1' in odd  positions
        
        int len = s.length();
        vector<vector<int>> cnt(2, vector<int>(2, 0));
        int ans = INT_MAX;
        
        // Calculate count of 0's and 1's at odd and even places
        for (int i = 0; i < len; i++) {
            cnt[s[i] - '0'][i % 2]++;
        }
        
        ans = min(ans, cnt[0][0] + cnt[1][1]);
        ans = min(ans, cnt[1][0] + cnt[0][1]);
        
        // Check with Remove operation 
        for (int i = 0; i < len; i++) {
            // Remove from front
            cnt[s[i] - '0'][i % 2]--;
            // Add at back
            cnt[s[i] - '0'][(i+len) % 2]++;
            
            ans = min(ans, cnt[0][0] + cnt[1][1]);
            ans = min(ans, cnt[1][0] + cnt[0][1]);
        }

        return ans;
    }
};

/*

**************** Logic ****************
        // Pattern 1 - 101010...
        // Flips required = count 0's at even and 1's at odd places
        // Pattern 2 - 010101...
        // Flips required = count 1's at even and 0's at odd places
        
        // cnt[0][0] = number of '0' in even positions
        // cnt[0][1] = number of '0' in odd  positions
        // cnt[1][0] = number of '1' in even positions
        // cnt[1][1] = number of '1' in odd  positions

        ans = min(flips to make pattern 1, flips to make pattern 2)
*/
