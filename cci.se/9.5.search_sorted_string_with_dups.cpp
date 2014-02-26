#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int bs_with_dups(vector<string> arr, string target){
	int start=0;
	int end=arr.size()-1;
	while(start<=end){
		int mid=(start+end)/2;
		int l=mid,r=mid;
		while (r<=end&&arr[r]=="")
			r++;
		while (l>=start&&arr[l]=="")	
			l--;

		if (r<=end&&arr[r]==target) return r;
		if (l>=start&&arr[l]==target) return l;

		if (target<arr[l]) end=l-1;
		else start=r+1;
	}
	return -1;
}

int main(){
	vector<string> arr(13,"");
	arr[0]="at";
	arr[4]="ball";
	arr[7]="car";
	arr[10]="dad";

	cout<<"Found \"at\" at "<<bs_with_dups(arr,"at")<<endl;
	cout<<"Found \"ball\" at "<<bs_with_dups(arr,"ball")<<endl;
	cout<<"Found \"car\" at "<<bs_with_dups(arr,"car")<<endl;
	cout<<"Found \"dad\" at "<<bs_with_dups(arr,"dad")<<endl;
	cout<<"Found \"dadcar\" at "<<bs_with_dups(arr,"dadcar")<<endl;
}
		

	
