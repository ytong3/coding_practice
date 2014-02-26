#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

void permute(string str, int index, vector<string> &ans_coll){
	if (index==str.length()){
		ans_coll.push_back(str);
		return;
	}
	
	for (int i=index;i<str.length();i++){
		swap(str[i],str[index]);
		permute(str,index+1,ans_coll);
		//swap back
		swap(str[i],str[index]);
	}
}

int main(int argc, char** argv){	
	if (argc!=2) {cerr<<"Check usage"<<endl;exit(0);}
	
	string str(argv[1]);
	vector<string> ans_coll;
	permute(str,0,ans_coll);
	for (string str:ans_coll)
		cout<<str<<endl;
}
