#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int find_in_rotated_array(vector<int> arr, int target){
	//binary search
	//iterative
	int start=0,end=arr.size()-1;
	while(start<=end){
		int mid = start+(end-start)/2;
		int midval=arr[mid];
		if (midval==target) return mid;
		if (midval<target){
			if (target<arr[end]){
				start=mid+1;
				continue;
			}else{
				end=mid-1;
				continue;
			}
		}else{
			if(target>arr[start]){
				end=mid-1;
				continue;
			}else{
				start=mid+1;
				continue;
			}
		}
	}
	return -1;
}

int main(){
	int a[]={15,16,19,20,25,1,3,4,5,7,10,14};
	vector<int> arr(a,a+12);
	cout<<"Char is found in POS: "<<find_in_rotated_array(arr,5)<<endl;
}
	
