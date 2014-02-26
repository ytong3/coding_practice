#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

vector<string> gen_valid_paren(int n, int index){
	if (index==0) {return vector<string>(1,"");}
	vector<string> ans_coll=gen_valid_paren(n,index-1);

	vector<string> res;
	for(string ans:ans_coll){
		res.push_back("()"+ans);
		if (ans!="") res.push_back("("+ans+")");
		if("()"+ans!=ans+"()")	res.push_back(ans+"()");
	}
	return res;
}


void generator(vector<string>&,string,int,int,int);
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    if (n>0) generator(ans, "", 0, 0, n);
    return ans;
}

//idea: recursively build string s. for every node in the recursion tree, it has two branches: 1) put '(' at the current spot, 2) put ')' at the current spot. At any time, # of '(' does not exceed that of ')'.

void generator(vector<string> & ans, string s, int l, int r, int n) { // r/l: appearance of ) (
    if (l == n) {
        ans.push_back(s.append(n-r, ')'));
        return;
    }
    generator(ans, s+'(', l+1, r, n);
    if (l>r) generator(ans, s+")", l, r+1, n);
}
	
int main(int argc, char** argv){
	if (argc!=2){
		cerr<<"Check usage"<<endl;
		exit(0);
	}

	int n=atoi(argv[1]);
	vector<string> ans_coll=gen_valid_paren(n,n);
	for (string str:ans_coll)
		cout<<str<<endl;
	cout<<"-------------------------"<<endl;
	ans_coll.clear();
	ans_coll=generateParenthesis(n);
	for (string str:ans_coll)
		cout<<str<<endl;
}
