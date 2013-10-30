/*
Given a sorted array of strings which is interspersed with empty strings, write a method to find the location of a given string.
*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

int find_idx(vector<string> str_arr, string target, int idx1, int idx2){
	if (str_arr.size()==0)
		return -1;
	
	if (idx1==idx2)
		if (str_arr[idx1]==target)
			return idx1;
		else
			return -1;
	
	int mid = (idx1+idx2)/2;

	int mid1(mid), mid2(mid);
	while(str_arr[mid1]=="")
		mid1--;
	while(str_arr[idx1]=="")
		idx1++;
	while(str_arr[mid2]=="")
		mid2++;
	while(str_arr[idx2]=="")
		idx2--;
	
	if(target<=str_arr[mid1])
		return find_idx(str_arr,target,idx1,mid1);
	else return find_idx(str_arr,target,mid2,idx2);
}


int main(){
	vector<string> arr;
	arr.push_back("at");
	for(int i=0;i<3;i++){
		arr.push_back("");
	}

	arr.push_back("ball");
	arr.push_back("");
	arr.push_back("");
	arr.push_back("");	
	arr.push_back("car");
arr.push_back("");
arr.push_back("");
arr.push_back("dad");
arr.push_back("");
arr.push_back("");
	
	cout<<find_idx(arr,"car",0,arr.size()-1);
}
