/*

**************** Problem Description ****************
Given a characters array letters that is sorted in non-decreasing order and a character target, return the smallest character in the array that is larger than target.

Note that the letters wrap around.

For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'.


    Example1 : 

    Input: letters = ["c","f","j"], target = "a"

    Output: "c"


    Example2 : 

    Input: letters = ["c","f","j"], target = "c"

    Output: "f"


    Example3 : 

    Input: letters = ["c","f","j"], target = "d"

    Output: "f"


    Example4 : 

    Input: letters = ["c","f","j"], target = "g"

    Output: "j"


    Example5 : 

    Input: letters = ["c","f","j"], target = "j"

    Output: "c"

*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = 0;
        int end = letters.size() - 1;
        
        while (start <= end) {
            int mid = (start + end) / 2;
            
            if (letters[mid] > target) end = mid - 1;
            else start = mid + 1;
        }
        
        start = start % letters.size();
        return letters[start];
    }
};

/*

**************** Logic ****************
Regular Binary search.

*/
