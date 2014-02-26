#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

template<typename _T>
void sort_stack(stack<_T> &s) {
	stack<_T> aux;
	
	while (!s.empty()) {
		_T temp = s.top();
		s.pop();
		while (!aux.empty() && temp<aux.top()) {
			s.push(aux.top());
			aux.pop();
		}
		aux.push(temp);
	}	
	s = aux;
}

int main(){
	stack<int> s;
	s.push(4);
	s.push(3);
	s.push(5);
	s.push(6);
	s.push(2);

	sort_stack(s);
	while (!s.empty()) {
		cout<<s.top()<<endl;
		s.pop();
	}
}
