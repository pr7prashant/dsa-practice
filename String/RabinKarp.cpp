/*

**************** Problem Description ****************
Rabin-Karp Algorithm for Pattern Searching

*/

#include <bits/stdc++.h>

#define ll long long
#define prime 101
#define mod 1e8

using namespace std;

ll calculateHash(string& str, ll start, ll end) {
    ll hash = 0;
    for (ll i = 0; i <= end - start; i++) {
        hash += (ll)(str[i] * (ll)pow(prime, i) % (ll)mod);
        hash = hash % (ll)mod;
    }
    return hash;
}

bool checkEqual(string& txt, string& pat, ll start1, ll end1, ll start2, ll end2) {
    if (end1 - start1 != end2 - start2) return false;
    
    while (start1 <= end1 && start2 <= end2) {
        if (txt[start1] != pat[start2]) return false;
        start1++;
        start2++;
    }
    
    return true;
}

ll recalculateHash(string& txt, ll prevIdx, ll nextIdx, ll hash, ll patLen) {
    hash -= txt[prevIdx];
    hash /= prime;
    hash += (ll)(txt[nextIdx] * (ll)pow(prime, patLen - 1) % (ll)mod);
    hash = hash % (ll)mod;
    
    return hash;
}

int main() {
    string txt, pat;
    cin >> txt >> pat;
    
    ll txtLen = txt.length();
    ll patLen = pat.length();

    // Calculate Hash of Pattern
    ll patternHash = calculateHash(pat, 0, patLen - 1);
        
    // Calculate Hash of First Window
    ll windowHash = calculateHash(txt, 0, patLen - 1);
    
    // Do Rolling Hash for Pattern Matching
    for (ll i = 0; i <= txtLen - patLen; i++) {
        if (
            windowHash == patternHash &&
            checkEqual(txt, pat, i, i + patLen - 1, 0, patLen - 1)
        ) {
            cout << "Pattern " << pat << " found at index : " << i << endl;
            return 0;
        }
        
        if (i + patLen < txtLen) {
            windowHash = recalculateHash(txt, i, i + patLen, windowHash, patLen);
        }
    }
    
    cout << "Pattern " << pat << " not found" << endl;
    
    return 0;
}

/*

**************** Logic ****************
Rabin-Karp algorithm slides the pattern one by one in the text string.
Rabin Karp algorithm matches the hash value of the pattern with the hash value of current substring of text,
and if the hash values match then only it starts matching individual characters.

The average and best-case running time of the Rabin-Karp algorithm is O(n+m), but its worst-case time is O(n*m).
O(n*m) occurs when we get false matches. Eg. ABC and BAC can have same hash value.
We can reduce the number of false matches by using a strong hashing function.

*/
