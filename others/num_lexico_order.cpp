#include <iostream>

using namespace std;

void print_lexico_order (int num, int N){
	if (num>N)
		return;

	cout<<num<<endl;
	for(int i=0;i<10;i++){
		print_lexico_order(num*10+i,N);
	}
}

int main(){
	for (int i=1;i<10;i++)
		print_lexico_order(i,222);
}
	
	
	
	
	
	