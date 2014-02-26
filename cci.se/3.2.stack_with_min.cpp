#include <iostream>
#include <string>
#include <stack>

using namespace std;

template<typename _T>
class stackWithMin{
private:
	stack<_T> aux;//keeps track of the the min. but 
	stack<_T> s;
public:

	stackWithMin(){
		//stack<_T> aux;	
		//stack<_T> s;
	}
	void pop(){
		if (s.top()==aux.top())	
			aux.pop();
		s.pop();
	}

	void push(_T val){
		if (aux.empty())
			aux.push(val);
		else if(aux.top()>=val)
			aux.push(val);
		s.push(val);
	}

	_T top(){
		return s.top();
	}

	_T get_min(){
		return aux.top();
	}

	size_t size(){
		return s.size();
	}

	bool empty(){
		return s.empty();
	}
};

int main(){
	stackWithMin<double> test_obj;

	test_obj.push(23.3);
	test_obj.push(21.4);
	test_obj.push(40);
	test_obj.push(22);

	while (!test_obj.empty())
	{
		cout<<test_obj.top()<<endl;
		cout<<test_obj.get_min()<<endl;
		cout<<"******"<<endl;
		test_obj.pop();
	}
}

	

