/*

**************** Problem Description ****************

The game is simple. You initially have ‘H’ amount of health and ‘A’ amount of armor.
At any instant you can live in any of the three places - fire, water and air. After every unit time, you have to change your place of living.
For example if you are currently living at fire, you can either step into water or air.

If you step into air, your health increases by 3 and your armor increases by 2

If you step into water, your health decreases by 5 and your armor decreases by 10

If you step into fire, your health decreases by 20 and your armor increases by 5

If your health or armor becomes <=0, you will die instantly

Find the maximum time you can survive.

The first line consists of an integer t, the number of test cases.
For each test case there will be two positive integers representing the initial health H and initial armor A.
  
  
  Example 1 : 
  
  Input:
  3
  2 10
  4 4
  20 8
  
  Output:
  1
  1
  5
  
*/

#include <iostream>

using namespace std;

bool canSurviveWater(int h, int a) {
	return (h - 5 > 0 && a - 10 > 0);
}

bool canSurviveFire(int h, int a) {
	return (h - 20 > 0);
}

int getMaxTime(int h, int a) {
	int time = 0;
	int state = -1; // air - 0, water - 1, fire - 2
	
	while (h > 0 && a > 0) {
		if (state != 0) {
			state = 0;
			h += 3;
			a += 2;
			time += 1;
		} else {
			if (canSurviveWater(h, a)) {
				state = 1;
				h -= 5;
				a -= 10;
				time += 1;
			} else if (canSurviveFire(h, a)) {
				state = 2;
				h -= 20;
				a += 5;
				time += 1;
			} else {
				h = 0;
				a = 0;
			}
		}
		
	}
	
	return time;
}

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		int h, a;
		cin >> h >> a;
		cout << getMaxTime(h, a) << endl;
	}
	
	return 0;
}

/*

**************** Logic ****************
It is obvious that air is the best choice possible as it increases both armor and health but you can go to air alternately only.
So every odd(i.e 1,3,5...) move will be to air.

Now we have to decide what to do with even moves? So we have two choices Fire or water?
We have to be reasonable and choose such a move that keeps both H and A above 0.
Now jumping in fire costs health -20 even though it increases armor by 5, but hey wait, what is the use of increased armor if you don't get your health >0 .
So if H>5 and A>10 choose water as water does less damage than fire (-10 vs -20).

Now what if we are short of armor but have enough health? In that case we have no choice but to jump to fire.

*/
