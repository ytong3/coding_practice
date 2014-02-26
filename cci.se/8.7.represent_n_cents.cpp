#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int way_to_present(int n, int type){
	if (type==3) return 1;
	int deno = 0;
	switch(type){
	case 0:
		deno=25;
		break;
	case 1:
		deno=10;
		break;
	case 2:
		deno=5;
		break;
	case 3:
		deno=1;
		break;
	default:
		deno=1;
	}
	
	int n_max = n/deno;
	int res(0);
	for (int i=0;i<=n_max;i++)
		res+=way_to_present(n-i*deno,type+1);
	
	return res;
}

int main(int, char** argv){
	int n = atoi(argv[1]);
	cout<<"Ways to represent "<<n<<" cents: "<<way_to_present(n,0)<<endl;
}
		
