/*
Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents) and
pennies (1 cent), write code to calculate the number of ways of representing n cents.


//when using recursion, remember that you can pass extra params to the recuring function!! They will come in handy used properly.
*/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > make_change(int sum){
	vector<int> res(4,0);

	if(sum==0){
		return sum;
	}

	
