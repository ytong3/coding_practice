#include <iostream>
#include <string>
#include <vector>

using namespace std;

void set_bits(int &N, int M, int i, int j){
	int max = ~0;
	int temp = ~0-((1<<j)-1);
	int temp2 = 1<<i-1;
	int mask =temp2|temp;
	N = N&mask&(M<<i);
}
