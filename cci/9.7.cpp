/*
A circus is designing a tower routine consisting of people standing atop one another’s shoulders. For practical and aesthetic reasons, each person must be both shorter and lighter than the person below him or her. Given the heights and weights of each person in the circus, write a method to compute the largest possible number of people in such a tower.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare_by_height(vector<int> a, vector<int> b){
	return a[0]<b[0];
}

bool compare_by_weight(vector<int> a, vector<int> b){
	return a[1]<b[1];
}


int find_max(vector<vector<int> > cast){
	vector<vector<int> > sorted1(cast);
	vector<vector<int> > sorted2(cast);

	sort(sorted1.begin(),sorted1.end(),compare_by_height);
	sort(sorted2.begin(),sorted2.end(),compare_by_weight);

	vector<int> order;
	
	for(int idx2=0;idx2<sorted2.size();idx2++){
		for(int idx1=0;idx1<sorted1.size();idx1++)
			if (sorted2[idx2][0]==sorted1[idx1][0]){
				order.push_back(idx1);
				break;
			}
	}

	int larger_counter(0), smaller_counter(0);
	for(int idx=0;idx<order.size();idx++){
		if(order[idx]>idx)
			larger_counter++;
		else
			smaller_counter++;
	}

	return max(larger_counter,smaller_counter);
}

int main(){
	vector<int> person;
	vector<vector<int> > cast;
	person.push_back(65);
	person.push_back(100);

	cast.push_back(person);

	person.clear();
	person.push_back(70);
	person.push_back(200);
	cast.push_back(person);
	
	person.clear();
	person.push_back(56);
	person.push_back(90);
	cast.push_back(person);
	
	person.clear();
	person.push_back(75);
	person.push_back(190);
	cast.push_back(person);
	
	person.clear();
	person.push_back(60);
	person.push_back(95);
	cast.push_back(person);
	
	person.clear();
	person.push_back(68);
	person.push_back(110);
	cast.push_back(person);
	
	cout<<find_max(cast)<<endl;
}

		
	

