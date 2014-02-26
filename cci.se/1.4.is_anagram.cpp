#include <iostream>
#include <string>
using namespace std;

bool is_anagram_sort(string s1, string s2) {
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());

	return s1==s2;
}

bool is_anagram_hash(string s1, string s2) {
	int check[256]={0};
	
	for(int i=0;i<s1.length();i++)
		check[s1[i]]++;

	for(int i=0;i<s2.length();i++)
		check[s2[i]]--;

	for(int i=0;i<256;i++)
		if (check[i]!=0)
			return false;
	return true;
}

int main(){
	//testing
	string s1("anagram");
	string s2("naargma");

	cout<<(is_anagram_sort(s1,s2)?"true":"false")<<endl;
	cout<<(is_anagram_hash(s1,s2)?"true":"false")<<endl;
}