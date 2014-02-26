#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>


using namespace std;

string dec2bin(double);

//utility functions
bool get_bit (int n, int index) {
	return (n&1<<index)>0;
}
int set_bit(int n, int index, bool b) {
	if (b) {
		return n|(1<<index);
	}

	return n&(~(1<<index));
}

int get_next(int n) {
	if (n==0) return 0;
	int i;
	for(i=0;i<32;i++)
		if(get_bit(n,i))
			break;
	int count=0;	
	for(;i<32;i++){
		if(get_bit(n,i)==false){
			n=set_bit(n,i,true);
			n=set_bit(n,i-1,false);
			break;
		}
		else{
			++count;
			n=set_bit(n,i,false);
		}
	}

	for(i=0;i<count-1;i++){
		n=set_bit(n,i,true);
	}
	return n;
}

int main(int argc, char** argv){	
	if(argc>2){
		cout<<"Check usage"<<endl;
		exit(0);
	}

	int j=atoi(argv[1]);
	j = get_next(j);
	cout<<dec2bin(j)<<endl;
}
	
