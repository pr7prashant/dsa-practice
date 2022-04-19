/*

**************** Problem Description ****************

The member states of the UN are planning to send 2 people to the moon. They want them to be from different countries.
You will be given a list of pairs of astronaut ID's. Each pair is made of astronauts from the same country.
Determine how many pairs of astronauts from different countries they can choose from.


    Example : 1
    
    Input:
    5 3
    0 1
    2 3
    0 4

    Output: 6

    Explanation: 
    Persons numbered [0,1,4] belong to one country, and those numbered [2,3] belong to another. The UN has 6 ways of choosing a pair:
    [0,2], [0,3], [1,2], [1,3], [4,2], [4,3]


    Example : 2
    
    Input:
    4 1
    0 2

    Output: 5

    Explanation: 
    Persons numbered [0,2] belong to one country, but persons 1 and 3 don't share countries with anyone else. The UN has 5 ways of choosing a pair:
    [0,1], [0,3], [1,2], [1,3], [2,3]

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */

void dfs(map<int, vector<int>> &graph, vector<bool> &visited, vector<int> &comps, int src) {
    visited[src] = true;
    comps.push_back(src);
    
    for (int n : graph[src]) {
        if (!visited[n]) dfs(graph, visited, comps, n);
    }
}

long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    // Create Graph
    map<int, vector<int>> graph;
    for (int i = 0; i < n; i++) {
        graph[i] = vector<int>();
    }
    
    for (vector<int> ast : astronaut) {
        graph[ast[0]].push_back(ast[1]);
        graph[ast[1]].push_back(ast[0]);
    }
    
    // DFS to find components
    vector<bool> visited(n, false); 
    vector<vector<int>> components;
    for (int i = 0; i < n; i++) {
        vector<int> comps;
        if (!visited[i]) dfs(graph, visited, comps, i);
        components.push_back(comps);
    }
    
    // Calculate Combinations
    long long ans = 0;
    long long presum = 0;
    for (vector<int> comp : components) {
        ans += presum * comp.size();
        presum += comp.size();
    }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    long long result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

/*

**************** Logic ****************
Represent the given data in the form of a graph.
Then find the number of connected components in the graph using DFS. Each component represent a country.
Now we know the number of counties and the population of each country, find the number of combinations possible.

We need to find the distinct sets (i.e. if x and y are from same country, they belong to same set) to get the answer. Let's say set A has a elements,set B has b elements.

Answer = a x b. [Because actual formula is to select one from set A and another one from set B = aC1 x bC1 = a x b]

Similarly, let's calculate answer for 4 sets - A,B,C,D with a,b,c,d elements respectively.

Lets say somehow I find set A has a elements.

Answer = 0 (Since I don't have another country to pair with)

Now, I find set B with b elements.

Answer = axb; .................................................(1)

Then, I find set C with c elements.

Answer = (axb) + (axc) + (bxc) [because we can select a pair from A and B, or A and C or B and C]

But this can be written as

Answer = (axb) + (a+b)xc ......................................(2)

Now I find set D with d elements, and I've examined all people.

Answer = (axb) + (axc) + (axd) + (bxc) + (bxd) + (cxd)

Or

Answer = (a)xb + (a+b)xc + (a+b+c)xd ..........................(3)

Do you see the pattern? That means when we find a new set, the new answer is the old answer + the sum of old values x new value.

*/
