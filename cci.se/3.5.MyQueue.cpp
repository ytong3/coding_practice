#include <iostream>
#include <string>
#include <stack>
using namespace std;

class MyQueue {
private:
	stack<int> in;
	stack<int> out;
	size_t sz;
public:
	void push_back(int val) {
		in.push(val);
		sz++;
	}

	void pop_front() {
		if (!out.empty()){//if anything is in stack out. just pop. DO not move elements from in to out. Or it will mess the order up.
			out.pop();
			sz--;
		}else{
			while(!in.empty()) {out.push(in.top());in.pop();}
			out.pop();
			sz--;
		}
	}

	int front() {
		if (!out.empty()) return out.top();
		
		while (!in.empty()) {
			out.push(in.top());
			in.pop();
		}
		return out.top();
	}
	
	size_t size(){
		return sz;
	}
};

int main(){
	MyQueue q;
	q.push_back(1);
	q.push_back(5);
	q.push_back(23);
	q.push_back(12);
	q.pop_front();
	q.pop_front();
	q.push_back(52);

	while (q.size()){
		cout<<q.front()<<endl;
		q.pop_front();
	}
}
	
		