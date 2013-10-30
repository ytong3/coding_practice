//if A has large enough space, we can find the length (the end point) of the new array and fill the array backward.

#include <iostream>
#include <vector>
using namespace std;

void merge_sorted(vector<int> &A, vector<int> &B){
	if(B.size()==0)
		return;

	int pa(0), pb(0);

	while(pa<A.size()&&pb<B.size()){
		if(A[pa]<B[pb])
			pa++;
		else{
			A.insert(A.begin()+pa,B[pb]);
			pb++;
			pa++;
		}
	}

	if(pa==A.size()){//A runs out before B
		//append the rest of B to A
		while(pb<B.size()){
			A.push_back(B[pb]);
			pb++;
		}
	}
}

int main(){
	vector<int> a, b;
	a.push_back(2);
	a.push_back(4);
	a.push_back(5);
	a.push_back(9);
	a.push_back(10);

	b.push_back(1);
	b.push_back(3);
	b.push_back(7);
	b.push_back(11);
	b.push_back(12);
	b.push_back(43);
	b.push_back(49);

	merge_sorted(a,b);
	
	for(int idx=0;idx<a.size();idx++){
		cout<<a[idx]<<endl;
	}
}
