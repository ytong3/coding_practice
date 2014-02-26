#include <iostream>

using namespace std;

void print_lexico_order (int num, int N){
	if (num>N){
		//print_lexico_order(num+1,N);
		return;
	}
	
	for(int i=0;i<10;i++){
		if(num<=N){
			cout<<num<<endl;
			num*=10;
			print_lexico_order(num,N);
			num/=10;
			num++;
			if(num%10==0) {return;}
		}
	}
}

int main(){
	print_lexico_order(11,222);
}