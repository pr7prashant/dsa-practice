/*

**************** Problem Description ****************
Given an array of integers nums, sort the array in increasing order based on the frequency of the values.
If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.


    Example : 1

    Input: nums = [1,1,2,2,2,3]

    Output: [3,1,1,2,2,2]

    Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.


    Example : 2

    Input: nums = [2,3,1,3,2]

    Output: [1,3,3,2,2]

    Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.


    Example : 3

    Input: nums = [-1,1,-6,4,5,-6,1,4,1]

    Output: [5,-1,4,4,-6,-6,1,1,1]


*/


// Custom comparison for min heap to handle the elements which have same frequency
struct comp {
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
	    // If frequncy of p1 and p2 is equal then return the greater element
        if (p1.first == p2.first) return p1.second < p2.second;
        
		// Else return the element with smaller frequency
        return p1.first > p2.first;
    }
};

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
	    // The data in priority_queue will be pair<frequency, arr[i]> as we want to sort by frequency
        priority_queue< pair<int, int>, vector<pair<int, int>>, comp > pq;
        unordered_map<int, int> mp;
        vector<int> res;
        
		// Store the frequency of elements in map
        for (int num : nums) mp[num]++;
        
		// Insert all the elements in map into min heap
        for (auto it = mp.begin(); it != mp.end(); it++) {
            pq.push({ it->second, it->first });
        }
        
		// Remove elements from heap and insert in result vector
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
			// Inserting the element top.first times, where top.first is the frequency of element
            while (top.first > 0) {
                res.push_back(top.second);
                top.first -= 1;                
            }
        }
        
        return res;
    }
};

/*

**************** Logic ****************
Create a map and store the frequency of elements in it.
Create a min heap and insert all elements from map as pair of frequency and element. Min heap because we want the the result in increasing order of frequency that is lowest frequency first.
The element with the minimum frequency will be at the top of heap. Pop the top element and insert the top element in the result array n times, where n is the frequency of the element.
Repeat step 3 until the heap is empty.

*/
