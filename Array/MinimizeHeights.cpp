/*

**************** Problem Description ****************

Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once.
After modifying, height should be a non-negative integer. 
Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.

A slight modification of the problem can be found here.


    Example1 : 

    Input:
    K = 2, N = 4
    Arr[] = {1, 5, 8, 10}

    Output: 5

    Explanation:
    The array can be modified as  {3, 3, 6, 8}. The difference between the largest and the smallest is 8-3 = 5.


    Example2 : 

    Input:
    K = 3, N = 5
    Arr[] = {3, 9, 12, 16, 20}

    Output: 11

    Explanation:
    The array can be modified as {6, 12, 9, 13, 17}. The difference between the largest and the smallest is 17-6 = 11. 

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        vector<pair<int, int>> v;
        unordered_map<int, int> mp;
        
        sort(arr, arr + n);
        v.push_back({arr[0] + k, arr[0]});
        if (arr[0] - k >= 0) v.push_back({arr[0] - k, arr[0]});
        mp[arr[0]] = 0;
        
        for (int i = 1; i < n; i++) {
            // Avoid duplicate elements
            if (arr[i] != arr[i-1]) {
                v.push_back({arr[i] + k, arr[i]});
                if (arr[i] - k >= 0) v.push_back({arr[i] - k, arr[i]});
                
                mp[arr[i]] = 0;
            }
        }
        
        int distinctTowers = mp.size();
        
        sort(v.begin(), v.end());
        
        // Variable size sliding window
        int count = 0;
        int i = 0, j = 0;
        int ans = v[v.size() - 1].first - v[0].first;
        
        while (j < v.size()) {
            if (mp[v[j].second] == 0) count++;
            mp[v[j].second] += 1;
            
            if (count == distinctTowers) {
                while (count == distinctTowers) {
                    int temp = v[j].first - v[i].first;        
                    ans = min(ans, temp);
                    
                    mp[v[i].second] -= 1;
                    if (mp[v[i].second] == 0) count--;
                    i++;
                }
            }

            j++;
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}

/*

**************** Logic ****************
For each tower add store the minimum (h-k) and maximum (h+k) height in an array.
Now we need to find windows in this array which contains all distict height towers.
For each such window calculate the height difference between smallest and largest tower and store the minimum.

*/
