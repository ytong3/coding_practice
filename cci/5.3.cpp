#include <iostream>
using namespace std;

int next_smallest(int n){
	//see how many 1's are there in n's binary representation
	int counter=0;
	int tmp_n=n;
	while(tmp_n>0){
		if(tmp_n%2)
			counter++;
		tmp_n/=2;
	}

	int res=1<<counter-1;
	res = (1<<31)|res;
	return res;
}

int next_largest(int n){
	int counter=0;
	int tmp_n=n;
	while(tmp_n>0){
		if(tmp_n%2)
			counter++;
		tmp_n/=2;
	}

	int res=1<<counter-1;
	res = res<<(31-counter);
	return res;
}

int main(){
	cout<<next_smallest(23)<<endl;
	cout<<next_largest(23)<<endl;
}
