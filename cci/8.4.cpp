/*
Write a method to compute all permutations of a string.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> str_permute(string str, int start){
	if(str.length()==start){
		vector<string> res;
		res.push_back("");
		return res;
	}

	vector<string> pre_res=str_permute(str,start+1);
	vector<string> res;
	for(int idx=0;idx<pre_res.size();idx++){
		string cur_str=pre_res[idx];
		cout<<"DEB "<<cur_str<<endl;
		//insert str[start]
		for(int idx2=0;idx2<cur_str.length();idx2++){
			cur_str.insert(idx2,1, str[start]);
			res.push_back(cur_str);
			cur_str.erase(cur_str.begin()+idx2);
		}
		res.push_back(cur_str+str[start]);
	}
    cout<<"DEB END REC"<<endl;
	return res;
}

int main(){
	string a="abc";
	
	vector<string> res=str_permute(a,0);

	for(int idx=0;idx<res.size();idx++)
		cout<<res[idx]<<endl;

}

	
