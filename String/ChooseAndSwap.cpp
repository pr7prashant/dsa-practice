/*

**************** Problem Description ****************

You are given a string s of lower case english alphabets.
You can choose any two characters in the string and replace all the occurences of the first character with the second character 
and replace all the occurences of the second character with the first character. 
Your aim is to find the lexicographically smallest string that can be obtained by doing this operation at most once.
  
  
  Example : 1
     
  Input:
  A = "ccad"
  
  Output: "aacd"
  
  Explanation:
  In ccad, we choose ‘a’ and ‘c’ and after doing the replacement operation once we get, 
  aacd and this is the lexicographically smallest string possible. 
  
  
  Example : 2
     
  Input:
  A = "abba"

  Output: "abba"
  
  Explanation:
  In abba, we can get baab after doing the replacement operation once for ‘a’ and ‘b’ 
  but that is not lexicographically smaller than abba. So, the answer is abba. 
  
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string chooseandswap(string a){
        vector<int> dict(26, -1);
        
        for (int i = 0; i < a.length(); i++) {
            if (dict[a[i] - 'a'] == -1) {
                dict[a[i] - 'a'] = i;
            }
        }
        
        int i, j;
        bool flag = false;
        for (i = 0; i < a.length(); i++) {
            for (j = 0; j < a[i] - 'a'; j++) {
                if (dict[j] > dict[a[i] - 'a']) {
                    flag = true;
                    break;
                }
            }
            
            if (flag) break;
        }
        
        if (!flag) return a;
        
        char ch1 = a[i];
        char ch2 = 'a' + j;
        for (int k = 0; k < a.length(); k++) {
            if (a[k] == ch1) a[k] = ch2;
            else if (a[k] == ch2) a[k] = ch1;
        }
        
        return a;
    }
    
};

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}

/*

**************** Logic ****************
First we store the first appearance of every character in a string in a hash array chk[].
The in order to find the lexicographically smaller string, the leftmost character must be replaced with some character which is smaller than it.
This will only happen if the smaller character appears after it in the array.
So, starting traversing the string from the left and for every character,
find the smallest character (even smaller than the current character) that appears after swap all of their occurrences to get the required string.
If no such character pair is found in the previous string then print the given string as it is the smallest string possible.

*/
