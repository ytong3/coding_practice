/*
Write a method that returns all subsets of a set.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > subset(vector<int> set, int start){
	vector<vector<int> > res;
	
	if(set.size()==0)
		return res;
	if(start==set.size()-1){
		vector<int> tmp;
		tmp.clear();
		res.push_back(tmp);
		tmp.push_back(set[start]);
		res.push_back(tmp);
		return res;
	}

	vector<vector<int> > pre_res=subset(set,start+1);
	
	for(int idx=0;idx<pre_res.size();idx++){
		res.push_back(pre_res[idx]);
		pre_res[idx].push_back(set[start]);
		res.push_back(pre_res[idx]);
	}
	

	return res;
}

int main(){
	vector<int> v;
	v.push_back(1);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	vector<vector<int> > res=subset(v,0);

	for(int idx1=0;idx1<res.size();idx1++){
		for(int idx2=0;idx2<res[idx1].size();idx2++)
			cout<<res[idx1][idx2]<<" ";
		cout<<endl;
	}
}
	
