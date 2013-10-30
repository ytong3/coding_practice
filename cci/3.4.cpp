#include <iostream>
#include <stack>
#include <exception>
#include <vector>
using namespace std;

stack<int> stacks[3];

void hanoid_move(int top_plates, int from, int to){
	if(top_plates==0) return;
	if(top_plates==1){
		int plate=stacks[from].top();
		try{
			stacks[from].pop();
			stacks[to].push(plate);
		}catch(exception& e){
			cout<<e.what()<<endl;
		}
		cout<<"Move "<<plate<<" from "<<from<<" to "<<to<<endl;
		return;
	}

	//I am brilliant!
	int the_other=3-from-to;
	hanoid_move(top_plates-1,from, the_other);
	hanoid_move(1,from,to);
	hanoid_move(top_plates-1,the_other, to);
}

int main(){
	try{
		stacks[0].push(3);
		stacks[0].push(2);
		stacks[0].pop();
		stacks[0].pop();
		stacks[0].pop();
		stacks[0].pop();
		stacks[0].top();
	}catch(exception& e){
		cout<<"Error: "<<e.what()<<endl;
	}
	hanoid_move(3,0,2);

}


