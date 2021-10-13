/*

**************** Problem Description ****************

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
    

    Example : 1
    
    Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]

    Output: 5
    
    Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
    
    
    Example : 2
    
    Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]

    Output: 0
    
    Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

*/

class Solution {
public:
    void addNeighbours(map<string, vector<string>> &graph, string word, unordered_set<string> &dict) {
        graph[word] = vector<string>();
        string temp = word;
        
        for (int i = 0; i < word.length(); i++) {
            char og = temp[i];
            for (int j = 0; j < 26; j++) {
                temp[i] = 'a' + j;
                if (temp != word && dict.find(temp) != dict.end()) {
                    graph[word].push_back(temp);
                }
            }
            temp[i] = og;
        }
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), beginWord) == wordList.end()) {
            wordList.push_back(beginWord);
        };
        
        // Create Graph
        unordered_set<string> dict(wordList.begin(), wordList.end());
        map<string, vector<string>> graph;
        
        for (string w : wordList) {
            addNeighbours(graph, w, dict);    
        }
        
        if (
            graph.find(beginWord) == graph.end() ||
            graph.find(endWord) == graph.end()
        ) return 0;
        
        // Bidirectional Search
        queue<string> q_begin;
        queue<string> q_end;
        q_begin.push(beginWord);
        q_end.push(endWord);
        
        map<string, bool> visited_begin;
        map<string, bool> visited_end;
        
        int steps = 0;
        while (!q_begin.empty() && !q_end.empty()) {
            int n1 = q_begin.size();
            int n2 = q_end.size();

            steps++;
            while (n1--) {
                string front = q_begin.front();
                q_begin.pop();
                visited_begin[front] = true;

                if (visited_end.find(front) != visited_end.end()) return steps;

                for (string s : graph[front]) {
                    if (!visited_begin[s]) q_begin.push(s);
                }
            }
            
            steps++;
            while (n2--) {
                string front = q_end.front();
                q_end.pop();
                visited_end[front] = true;

                if (visited_begin.find(front) != visited_begin.end()) return steps;

                for (string s : graph[front]) {
                    if (!visited_end[s]) q_end.push(s);
                }
            }
        }
        
        return 0;
    }
};


/*

**************** Logic ****************
Create a graph considering each word as a node whose neighbours are words that differs by a single letter.
Now we can use BFS to find the shortest transformation(path) from beginWord to endWord.

For further optimization we can use Bidirectional Search.
The idea behind bidirectional search is to run two simultaneous searches—one forward from the initial state and the other backward from the goal—hoping that the two searches meet in the middle.
The motivation is that b^(d/2) + b^(d/2) is much less than b^d. b is branch factor, d is depth. 

*/
