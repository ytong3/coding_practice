#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <assert.h>

using namespace std;

string dish(int l){
	return string(l,'*');
}

void hanoi_recur_solver(int num, int from ,int to, vector<stack<string> > &poles) {
	assert(num<=poles[from].size());	
	
	if (num==0)
		return;
	int other = 3-from-to;

	//move num-1 to other;
	hanoi_recur_solver(num-1,from,other,poles);
	//move the last one to 'to'
	poles[to].push(poles[from].top());
	cout<<"Move "<<poles[from].top()<<" from Pole "<<from<<" to "<<to<<endl;
	POles[from].pop();
	
	//move the num-1 dishes from other to 'to' on that top of dish num
	hanoi_recur_solver(num-1,other,to,poles);
}


int main(){
	vector<stack<string> > poles(3,stack<string>());

	for (int i=5;i>0;--i)
		poles[0].push(dish(i));
	
	hanoi_recur_solver(poles[0].size(),0,2,poles);
}