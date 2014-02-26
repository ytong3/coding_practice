#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class comp{
public:
	bool operator()(string s1, string s2){
		sort(s1.begin(),s1.end());
		sort(s2.begin(),s2.end());
		
		return s1<s2;
	}
};

void sort_anagram(vector<string> &s){
	sort(s.begin(),s.end(),comp());
}

int main(){
	vector<string> ss;
	ss.push_back("anagram");
	ss.push_back("aangram");
	ss.push_back("zaze");
	ss.push_back("zeza");
	ss.push_back("anagmar");
	ss.push_back("zzae");
	ss.push_back("zeaz");
	
	sort_anagram(ss);
	for(string a:ss)
		cout<<a<<" ";
	cout<<endl;
}
