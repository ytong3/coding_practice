/*
Write a method to sort an array of strings so that all the anagrams are next to each
other.
*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//familiarize function sort!!
//implement a comparator for this and then use sort();
string get_signature(string str){
	vector<char> char_arr (str.begin(),str.end());//note that you cannot access element by str.end(), which points to the past-the-end charater of the string.
	sort(char_arr.begin(),char_arr.end());//using default comparator <
	return string(char_arr.begin(),char_arr.end());
}

//implement a new comparator

bool mycomparator(string a, string b){
	return get_signature(a)<get_signature(b);
}
	
int main(){
	vector<string> vs;
	/*
	vs.push_back("abc");
	vs.push_back("cba");
	vs.push_back("fes");
	vs.push_back("bcd");
	vs.push_back("bdc");
*/
	sort(vs.begin(),vs.end(),mycomparator);
	for(int idx=0;idx<vs.size();idx++)
		cout<<vs[idx]<<" ";
	cout<<endl;
}
