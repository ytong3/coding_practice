/*
Three things:
1. Consider clearly whether your function include or exclude the boudary indices it takes.
2. Use caution when deciding to use a < or <=.
3. The gist of this problem is to make sure the target locates in the given range.
4. the middle point of two index is (start+end)/2. e.g. 1 for 0,2, 0 for 0,1, and 4 for 4 and 5, etc. However, be crystal clear when using the index, whether they are included or excluded fothe function.
5. Do not use && to AND conditions in if unless you are 100% sure.

***This problem is essentially a binary search. Therefore, it can be solved without recursion. Use a while loop and constantly decrease the the search range.

*/





#include <iostream>
#include <vector>

using namespace std;

int find_element(vector<int> arr, int target, int idx1, int idx2){
	if(arr.size()==0)
		return -1;

	if(idx1==idx2){
		if(arr[idx1]==target)
			return idx1;
		else
			return -1;
	}

	int mid = (idx1+idx2)/2;

	//need to make sure that the target is within the range of vectors called with.
	if(arr[idx1]<arr[idx2]){
		if(target<=arr[mid])
			return find_element(arr,target, idx1, mid);
		else
			return find_element(arr,target, mid+1, idx2);
	}
	
	if (arr[idx1]<arr[mid]){
		if (target<=arr[mid]&&arr[idx1]<=target)
			return find_element(arr,target,idx1, mid);
		else
			return find_element(arr,target,mid+1,idx2);
	}
	
	if (arr[idx2]>arr[mid])
		if (arr[mid]<target&&target<arr[idx2])
			return find_element(arr,target,mid+1,idx2);
		else
			return find_element(arr,target,idx1,mid);
}
	



int main(){
	vector<int> arr;
	arr.push_back(4);
	arr.push_back(6);
	arr.push_back(7);
	arr.push_back(1);
	arr.push_back(3);
	arr.push_back

	cout<<find_element(arr,4,0,arr.size()-1)<<endl;
	cout<<find_element(arr,3,0,arr.size()-1)<<endl;
}


	
	
