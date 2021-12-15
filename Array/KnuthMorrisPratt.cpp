/*

**************** Problem Description ****************
Knuth–Morris–Pratt Algorithm for Pattern Searching

*/

#include <bits/stdc++.h>

using namespace std;

vector<int> generateLPS(string& pat) {
    vector<int> LPS(pat.length(), 0);
    
    int i = 0, j = 1;
    while (j < pat.length()) {
        if (pat[j] == pat[i]) {
            LPS[j] = i + 1;
            i++;
            j++;
        } else {
            if (i != 0) {
                i = LPS[i-1];
            } else {
                LPS[j] = 0;
                j++;          
            }
        }
    }
    
    return LPS;
}

int main() {
    string txt, pat;
    cin >> txt >> pat;
    
    int txtLen = txt.length();
    int patLen = pat.length();

    vector<int> LPS = generateLPS(pat);
    int i = 0, j = 0;
    
    while (i < txtLen && j < patLen) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
        } else {
            if (j != 0) {
                j = LPS[j-1];
            } else {
                i++;
            }
        }
    }
    
    if (j == patLen) {
        cout << "Pattern " << pat << " found at index : " << i - patLen << endl;
    } else {
        cout << "Pattern " << pat << " not found" << endl;
    }
        
    return 0;
}

/*

**************** Logic ****************
The KMP matching algorithm uses degenerating property (pattern having same sub-patterns appearing more than once in the pattern) of the pattern and improves the worst case complexity to O(n).
The basic idea behind KMP’s algorithm is: whenever we detect a mismatch (after some matches), we already know some of the characters in the text of the next window.
We take advantage of this information to avoid matching the characters that we know will anyway match.
KMP algorithm preprocesses pat[] and constructs an auxiliary lps[] of size m (same as size of pattern) which is used to skip characters while matching.

*/
