#include <cstring>
#include <iostream>
#include <climits>

using namespace std;

int atoint(char *str){
	char *p=str;
	bool sign = true;//default positive
    long long res = 0;

	while (*p&&*p==' ')  p++;
	if (!(*p)) return 0;
	
	if(*p<'0'||*p>'9'){
		if(*p=='-') {sign= false;p++;}
		else if(*p=='+') {p++;cout<<"Hello"<<endl;}
		else return 0;
	}

	int count=0;
	while (*p&&isdigit(*p)){
		int val = *p-'0';
        res=res*10+val;
        if (sign&&res>INT_MAX){
            return INT_MAX;
        }else if (!sign&&-res<INT_MIN) return INT_MIN;
        p++;
	}
    
    return sign?res:-res;
}

int main(int argc, char **argv){

	char str[] = "223432432432325";
	int res = atoint(str);
	cout<<res<<endl;
}
	
		