#include <iostream>
#include "stdlib.h"
using namespace std;

int f(int n){
	if(n==0) return 1;
	if(n==1) return 1;
	return f(n-1)+f(n-2);
}

int main(int argn, char** argv){
	if(argn!=2){
		cout<<"Usage: *.o [number]"<<endl;
		exit(0);
	}
	
	int n = atoi(argv[1]);
	cout<<f(n)<<endl;
}
