/*

**************** Problem Description ****************

Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.

Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
    

    Example : 1
    
    Input: 
    N = 5, K = 4
    dict = {"baa","abcd","abca","cab","cad"}
    
    Output: 1

    Explanation:
    Here order of characters is 'b', 'd', 'a', 'c' Note that words are sorted and in the given language "baa" comes before "abcd",
    therefore 'b' is before 'a' in output. Similarly we can find other orders.
    
    
    Example : 2
    
    Input: 
    N = 3, K = 3
    dict = {"caa","aaa","aab"}

    Output: 1

    Explanation:
    Here order of characters is 'c', 'a', 'b' Note that words are sorted and in the given language "caa" comes before
    "aaa", therefore 'c' is before 'a' in output. Similarly we can find other orders.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void addVertex(map<char, set<char>> &graph, string &first, string &second) {
        for (int i = 0; i < first.length(); i++) {
            if (i >= second.length()) return;
            
            if (first[i] == second[i]) continue;
            
            graph[first[i]].insert(second[i]);
            
            return;
        }
    }
    
    string topoSort(map<char, set<char>> &graph, int K) {
        string ans = "";
        map<char, int> indegree;
        for (auto it = graph.begin(); it != graph.end(); it++) {
            auto adj = it->second;
            for (auto itr = adj.begin(); itr != adj.end(); itr++) {
                indegree[*itr]++;
            }
        }
        
        queue<char> q;
        map<char, bool> visited;
        for (int i = 0; i < K; i++) {
            if (indegree['a' + i] == 0) q.push('a' + i);
            visited['a' + i] = false;
        }
        
        while (!q.empty()) {
            char front = q.front();
            q.pop();
            visited[front] = true;
            ans += front;
            
            for (char ch : graph[front]) {
                indegree[ch]--;
                
                if (!visited[ch] && indegree[ch] == 0) q.push(ch);
            }
        }
        
        return ans;
    }
    
    string findOrder(string dict[], int N, int K) {
        // Create Graph
        map<char, set<char>> graph;
        
        for (int i = 0; i < K; i++) {
            graph['a' + i] = set<char>();
        }
        
        for (int i = 0; i < N - 1; i++) {
            addVertex(graph, dict[i], dict[i+1]);
        }
        
        // Topological Sort
        return topoSort(graph, K);
    }
};

string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

/*

**************** Logic ****************
The idea is to create a graph of characters and then find topological sorting of the created graph. Following are the detailed steps.
 

1) Create a graph g with number of vertices equal to the size of alphabet in the given alien language. For example, if the alphabet size is 5, then there can be 5 characters in words. Initially there are no edges in graph.

2) Do following for every pair of adjacent words in given sorted array.
…..a) Let the current pair of words be word1 and word2. One by one compare characters of both words and find the first mismatching characters.
…..b) Create an edge in g from mismatching character of word1 to that of word2.

3) Print topological sorting of the above created graph. 

*/
