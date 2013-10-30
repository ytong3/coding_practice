#include <iostream>
#include <string>

using namespace std;

void parse_decimal_to_bin(string n){
	//the integer part;
	size_t found = n.find(".");
	
	if(n.length()-found>32){
		cout<<"ERROR!"<<endl;
		return;
	}
	
	int int_part=0;
	float dec_part = 0;
	float base=1;
	
	for(int idx=found-1;idx>=0;idx--){
		int_part+=(n[idx]-'0')*base;
		base=base*10;
	}
	
	base=0.1;
	for(int idx=found+1;idx<n.length();idx++){
		dec_part+=(n[idx]-'0')*base;
		base=base/10;
	}
	
	cout<<"HERE"<<endl;
	
	string int_part_str="";
	string res="";
	while(true){
		string tmp="";
		tmp=(int_part%2)?"1":"0";
		int_part_str=tmp+int_part_str;
		int_part=int_part/2;
		if(int_part<=0)
			break;
	}
	
	res=int_part_str+".";
	
	while(true){
		cout<<dec_part<<endl;
		if(dec_part==1){
			res+="1";
			break;
		}
		if(dec_part<=0)
			break;
		
		float r=dec_part*2;
		if(r>=1){
			res+="1";
			dec_part=r-1;
		}else{
			res+="0";
			dec_part=r;
		}		
	}
	
	cout<<res<<endl;
}

int main(){
	parse_decimal_to_bin("43543.45654345352");

}
