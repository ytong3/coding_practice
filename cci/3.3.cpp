#include <iostream>
#include <stack>
using namespace std;

class SetOfStacks{
public:
	static int threshold;
	int length;

	

	stack<stack<int> > data;
	int top(){
		return data.top().top();
	}
	
	void pop(){
		data.top().pop();
		if(data.top().size()==0)
			data.pop();
		
		length--;
	}
	
	void push(int val){
		if(data.top().size()==threshold){
			stack<int> newstack;
			data.push(newstack);
		}
		data.top().push(val);
		length++;
	}
	
	SetOfStacks(){
		length=0;
		data.push(*(new stack<int>));
	}
};

int SetOfStacks::threshold = 3;

int main(){
	SetOfStacks ss;
	ss.push(1);
	ss.push(4);
	ss.push(3);
	ss.push(2);
	ss.push(5);
	ss.push(12);
	while(ss.length){
		cout<<ss.top()<<endl;
		ss.pop();
	}
}
