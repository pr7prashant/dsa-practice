/*

**************** Problem Description ****************
Given a string s of lowercase alphabets and a number k,
the task is to print the minimum value of the string after removal of ‘k’ characters.
The value of a string is defined as the sum of squares of the count of each distinct character.


    Example : 1

    Input: s = abccc, k = 1

    Output: 6

    Explaination: We remove c to get the value as 12 + 12 + 22


    Example : 2

    Input: s = aabcbcbcabcc, k = 3

    Output: 27

    Explaination: We remove two 'c' and one 'b'. Now we get the value as 32 + 32 + 32.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minValue(string s, int k){
        priority_queue<int> pq;
        unordered_map<char, int> mp;
        int ans = 0;
        
        for (char ch : s) mp[ch]++;
        
        for (auto it = mp.begin(); it != mp.end(); it++) {
            pq.push(it->second);
        }
        
        while (k--) {
            int top = pq.top();
            pq.pop();
            top -= 1;
            
            if (top > 0) pq.push(top);
        }
        
        while (!pq.empty()) {
            int top = pq.top();
            pq.pop();
            ans += top * top;
        }
        
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}

/*

**************** Logic ****************
Store the frequency of characters in a map.
Create a max heap using the elements in map.
Decrement the frequency from top of the heap k times.
Add the square of remaining elements in the heap.

*/
