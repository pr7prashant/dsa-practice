/*

**************** Problem Description ****************

You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0.
At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1.
The player adds the chosen number to their score. The game ends when there are no more elements in the array.

Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true.
You may assume that both players are playing optimally.


    Example : 1
        
    Input: nums = [1,5,2]

    Output: false

    Explanation:
    Initially, player 1 can choose between 1 and 2. 
    If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
    So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
    Hence, player 1 will never be the winner and you need to return false.


    Example : 2
    
    Input: nums = [1,5,233,7]

    Output: true

    Explanation:
    Player 1 first chooses 1. Then player 2 has to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
    Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.

*/

class Solution {
public:
    bool helper(vector<int>& nums, int score1, int score2, int turn, int i, int j) {
        if (i > j) {
            if (turn == 0) {
                if (score1 >= score2) return true;
                return false;    
            } else {
                if (score1 < score2) return true;
                return false;
            }
        }
        
        // Player1's pick
        if (turn == 0) {
            return !helper(nums, score1 + nums[i], score2, 1, i+1, j) || !helper(nums, score1 + nums[j], score2, 1, i, j-1);
        }
        
        // Player2's pick
        return !helper(nums, score1, score2 + nums[i], 0, i+1, j) || !helper(nums, score1, score2 + nums[j], 0, i, j-1);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        return helper(nums, 0, 0, 0, 0, nums.size() - 1);
    }
};

/*

**************** Logic ****************
The main idea is each player will play optimally,
so if there exist that my opponent will lose the game (false), I will return true, that's why we use '!' in the return;

If players1 has to win, then recursive call for one of the players1's move should return false indicating that player2 lost, and vice-versa.

*/
