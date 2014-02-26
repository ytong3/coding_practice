#include <iostream>
#include <string>
#include <vector>

using namespace std;

//return all results should use dfs

void all_subsets(vector<int> s, int index,  vector<int> &ans, vector<vector<int> > &ans_coll){
	if (index==s.size()){
		ans_coll.push_back(ans);
		return;
	}

	
	ans.push_back(s[index]);
	all_subsets(s,index+1,ans,ans_coll);
	ans.pop_back();
	all_subsets(s,index+1,ans,ans_coll);
}

int main() {
	int a[]={1,2,4,3,5,6,9};
	vector<int> s(a,a+7);
	vector<int> ans;
	vector<vector<int> > ans_coll;
	all_subsets(s,0,ans,ans_coll);
	for(vector<int> t:ans_coll){
		for(int i: t)
			cout<<i;
		cout<<endl;
	}
	cout<<"Counts: "<<ans_coll.size()<<endl;
}
	

	
