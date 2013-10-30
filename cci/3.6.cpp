#include <iostream>
#include <stack>

using namespace std;

/*Write a program to sort a stack in ascending order. You should not make any assump-
tions about how the stack is implemented. The following are the only functions that
should be used to write this program: push | pop | peek | isEmpty.
*/

stack<int> sort(stack<int> s){
	stack<int> r;

	while(!s.empty()){
		int val=s.top();
		s.pop();
		
		while(!r.empty()&&r.top()>val){
			s.push(r.top());
			r.pop();
		}
		r.push(val);	
		cout<<s.size()<<endl;
	}
	return r;
}

int main(){
	stack<int> s;
	s.push(0);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	stack<int> r=sort(s);
	cout<<"Sorted stack: ";
	while(!r.empty()){
		cout<<r.top()<<" ";
		r.pop();
	}
	cout<<endl;
}
