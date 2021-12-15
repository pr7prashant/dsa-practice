/*

**************** Problem Description ****************

Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.


    Example : 1
        
    Input: S = "}{{}}{{{"

    Output: 3

    Explanation:
    One way to balance is: "{{{}}{}}".
    There is no balanced sequence that can be formed in lesser reversals.


    Example : 2
        
    Input: S = "{{}{{{}{{}}{{"

    Output: -1

    Explanation: There's no way we can balance this sequence of braces.

*/

#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

int countRev (string s) {
    if (s.length() % 2 == 1) return -1;
    
    int rev = 0, open = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '{') {
            open++;
        } else {
            if (open == 0) {
                rev++;
                open++;
            } else {
                open--;
            }
        }
    }
    
    rev += open / 2;
    
    return rev;
}

/*

**************** Logic ****************
Keep the track of the number of opening and closing braces as you traverse the sequence.
It's all fine till open ≥ close.
But, as close exceeds open, we need to do reversal.

*/
