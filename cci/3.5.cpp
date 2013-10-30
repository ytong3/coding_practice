#include <iostream>
#include <stack>

using namespace std;

//use two stacks to implement a MyQueue class

class MyQueue{
	stack<int> s1;
	stack<int> s2;
public:
	int pop(){
		while(s1.size()){
			s2.push(s1.top());
			s1.pop();
		}
		
		int res=s2.top();
		s2.pop();
		
		while(s2.size()){
			s1.push(s2.top());
			s2.pop();
		}
		
		return res;
	}
	
	int push(int val){
		s1.push(val);
	}
	
	int top(){
		while(s1.size()){
			s2.push(s1.top());
			s1.pop();
		}
		int res=s2.top();
		while(s2.size()){
			s1.push(s2.top());
			s2.pop();
		}
		return res;
	}
};

int main(){
	MyQueue q;
	q.push(1);
	q.push(4);
	q.push(43);
	q.push(54);
	
	cout<<q.top()<<endl;
	q.pop();
	q.pop();
	cout<<q.top()<<endl;
	
	stack<int> e;
	e.clear();
	e.pop();
	e.pop();
}
		
