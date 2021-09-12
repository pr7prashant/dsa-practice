/*

**************** Problem Description ****************

There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


  Example 1 : 
  
  Input:
  N = 6
  start[] = {1,3,0,5,8,5}
  end[] =  {2,4,6,7,9,9}

  Output: 4
  
  Explanation: 
  Maximum four meetings can be held with given start and end timings.
  The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
  
  
  Example 2 : 
  
  Input:
  N = 3
  start[] = {10, 12, 20}
  end[] = {20, 25, 30}
  
  Output: 1
  
  Explanation:
  Only one meetings can be held with given start and end timings.
  
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        int count = 0;
        pair<int, int> prev;
        
        vector<pair<int, int>> meetings;
        for (int i = 0; i < n; i++) {
            meetings.push_back({ end[i], start[i] });
        }
        
        sort(meetings.begin(), meetings.end());
        
        for (auto m : meetings) {
            if (count == 0 || m.second > prev.first) {
                prev = m;
                count++;
            }
        }
        
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}

/*

**************** Logic ****************
Sort the meetings according to their finishing time. Push the pair of starting and finish time and their index as pair in another list.
If the start time of current meeting is greater than or equal to the finish time of previously selected meeting then increment the counter and update previously selected meeting.
Return the counter.

*/
