#include <iostream>

using namespace std;

void set_substr(int &N, int &M, int i, int j){
	
	int mask=((1<<j)-1)-((1<<i)-1);
	mask = ~0-mask;

	N = (N&mask)|(M<<i);
}

int set_substr_1(int n, int m, int i, int j){
	int max=~0;
	
	int left=max-(1<<j);
	int right=(1<<i)-1;
	
	int mask=left|right;
	
	return (n&mask)|(m<<i);
}
	

int main(){
	int N=1<<10;
	int M=0x15;
	int temp=~0-1;
	
	set_substr(N,M,2,6);
	std::cout<<N<<"vs."<<M<<endl;
	std::cout<<set_substr_1(N,M,2,6)<<endl;
}
