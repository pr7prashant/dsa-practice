/*

**************** Problem Description ****************
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.


    Example : 1

    Input: s = "aab"
    Output: "aba"


    Example : 2

    Input: s = "aaab"
    Output: ""
  
*/


class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> mp;
        priority_queue< pair<int, char> > pq;
        string res = "";
        
        for (char ch : s) mp[ch] += 1;
        
        for (auto it = mp.begin(); it != mp.end(); it++) {
            pq.push({ it->second, it->first });
        }
        
        while (!pq.empty()) {
            auto top1 = pq.top();
            pq.pop();
            res += top1.second;
            
            if (!pq.empty()) {
                auto top2 = pq.top();
                pq.pop();
                res += top2.second;
                
                if (top2.first > 1) {
                    top2.first -= 1;
                    pq.push(top2);
                }
            }
            
            if (top1.first > 1) {
                top1.first -= 1;
                pq.push(top1);
            }
        }
        
        for (int i = 1; i < res.length(); i++) {
            if (res[i] == res[i-1]) return "";
        }
        
        return res;
    }
};

/*

**************** Logic ****************
Create a max heap with count of characters as key.
Append the top two most frequent characters in result string and their frequency in heap by one.
Repeat this process untill heap is empty.
Check if the resulting string has same adjacent characters or not and return result.

*/
