#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

template<typename _T>
class setOfStacks{
	vector<stack<_T> > ss;
	size_t stackLimit = 6;//is supported C++11
public:
	setOfStacks(){
		ss.clear();
	}

	void push(_T val){
		if (ss.size()==0)
			ss.push_back(stack<_T>());
		stack<_T> &last = ss.back();

		if (last.size()==stackLimit){
			ss.push_back(stack<_T>());
		last = ss.back();

		last.push(val);
		}
	}

	void pop(_T val){
		stack<_T> &last = ss.back();
		last.pop();
		if (last.empty()) ss.pop_back();
	}

	_T top(){
		stack<_T> &last = ss.back();
		try{
			return last.top();
		}catch(exception &e)
		{
			cout<<e.what();
		}
	}
}

		