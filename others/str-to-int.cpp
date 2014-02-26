#include <cstring>
#include <iostream>
#include <climits>

using namespace std;

int atoint(char *str){
	char *p=str;
	bool sign = true;//default positive

	while (*p&&*p==' ')  p++;
	if (!(*p)) return 0;
	
	if(*p<'0'||*p>'9'){
		if(*p=='-') {sign= false;p++;}
		else if(*p=='+') {p++;cout<<"Hello"<<endl;}
		else return 0;
	}

	int a[strlen(str)];
	int count=0;
	while (*p&&*p>='0'&&*p<='9'){
		a[count++]=*p-'0';
		p++;
	}

	int res=0;
	int i=0;
	for (i=0;i<count;i++){
		int	val = res*10;
		if (val/10!=res){
			res = INT_MAX;
			break;
		}
		res =val;
		val=res+a[i];

		if (val<res||val-a[i]!=res){
			cout<<"Hello"<<endl;
			res = INT_MAX;
			break;
		}
        //cout<<val<<endl;
		res = val;
	}

	if (i!=count){
		if(sign) return INT_MAX;
		else return INT_MIN;
	}
	if (sign)
		return res;
	return 0-res;
}

int main(int argc, char **argv){

	char str[] = "2147483648";
	int res = atoint(str);
	cout<<res<<endl;
}
	
		