/*

**************** Problem Description ****************

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


    Example : 1
    
    Input: strs = ["eat","tea","tan","ate","nat","bat"]
    
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]


    Example : 2
    
    Input: strs = [""]
    
    Output: [[""]]


    Example : 3
    
    Input: strs = ["a"]

    Output: [["a"]]

*/

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> mp;
            
            for (string word : strs) {
                string sorted = word;
                sort(sorted.begin(), sorted.end());
                mp[sorted].push_back(word);
            }
            
            vector<vector<string>> ans;
            for (auto it = mp.begin(); it != mp.end(); it++) {
                ans.push_back(it->second);
            }
            
            return ans;
        }
};

/*

**************** Logic ****************
All the anagrams will be equal after sorting.

*/
