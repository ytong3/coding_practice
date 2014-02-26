#include <iostream>
#include <string>
#include <vector>

using namespace std;

string dec2bin(double n){
	int i = (int) n;
	string res("");
	while (i>0){
		string ch(1,'0'+i%2);
		res=ch+res;
		i/=2;
	}

	
	double decPart = n - (int)n;
	if (decPart>0) res.push_back('.');
	string dec_str="";
	while (decPart>0){
		if (dec_str.length()>32) return "ERROR";
		if (decPart==1) {//this is a special case
			res.push_back('0'+1);
			return res;
		}

		double r = decPart*2;
		if (r>=1){
			res.push_back('1');
			decPart = r-1;
		}
		else{
			res.push_back('0');
			decPart = r;
		}
	}
	return res;
}
/*
int main() {
	cout<<dec2bin(34.3234)<<endl;
}
*/
