#include <iostream>

using namespace std;

double power_n(double x, int n){
	if (n==1) return x;
	if (n==0) return 1;
	double half = power_n(x,n/2);
	if (n%2==0) return half*half;
	if (n>0) return half*half*x;
	return half*half/x;
}

int main(){
	cout<<power_n(2,-5)<<endl;
}