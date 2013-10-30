//Remember to check for duplicates!!!


#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> validparen(int n){
	if(n==0)
		return vector<string>(1,"");

	if(n==1)
		return vector<string>(1,"()");

	vector<string> pre_res=validparen(n-1);
	vector<string> res;
	for(int idx=0;idx<pre_res.size();idx++){
		string tmp=pre_res[idx];
		res.push_back("("+tmp+")");
		string t_str1="()"+tmp;
		string t_str2=tmp+"()";
		//need to check for duplicates!
		res.push_back(t_str1);
		if(!(t_str1==t_str2))	
			res.push_back(t_str2);
	}

	return res;
}

int main(){
	vector<string> res = validparen(3);
	for(int idx=0;idx<res.size();idx++)
		cout<<res[idx]<<endl;
}
		
	
	
