#include <iostream>
#include <string>
using namespace std;

void remove_dup(string &str) {
	int front(0),back(0);

	while (back<str.length()) {
		char w=str[back];
		int i=0;
		for (;i<front;i++)
			if (str[i]==w)
				break;

		if (i==front)
			swap(str[front++],str[back++]);
		else
			back++;
	}
	str.resize(front);
	return;
}

//if a constant space is allowed, you can use hashmap or bitmap.
int main(){
	string a("hello, world");
	string b("bookkeepper");
	string c("");
	string d("rock the world");

	remove_dup(a);
	remove_dup(b);
	remove_dup(c);
	remove_dup(d);

	cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl;
}