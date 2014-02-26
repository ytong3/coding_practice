#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

//similar to the problme requiring replacing ' ' with %20.
int merge_sorted_array(int A[], int lA, int B[], int lB) {
	int len = lA+lB;
	int index = len-1;
	int cA = lA-1;
	int cB = lB-1;
	while (cA>=0&&cB>=0) {
		if (A[cA]>B[cB]){
			A[index--]=A[cA];
			cA--;
		}else{
			A[index--]=B[cB];
			cB--;
		}
	}

	if (cA<0)
		while (cB>=0)
			A[index--]=B[cB--];
	
	return len;
}


int main(){
	int A[100]={1,3,5,7,9};
	int B[]={2,4,6,8,10,13};
	int len =merge_sorted_array(A,5,B,6);
	for (int i=0;i<len;i++)
		cout<<A[i]<<" ";
	cout<<endl;
}

