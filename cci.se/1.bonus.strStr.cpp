#include <iostream>
#include <string>
using namespace std;

char* strStr(char* s1, char* s2){
	if (strlen(s1)<strlen(s2))
		return NULL;

	char *pBack = s1, *p1=s1, *p2=s2;
	
	//A very important piece of detail
	while (*++p2){
		pBack++;
	}

	while (*pBack) {
		char *pBegin = p1;
		p2 = s2;
		while(*p1&&*p2&&*p1==*p2){
			p1++;
			p2++;
		}

		if(!*p2) return pBegin;

		p1 = ++pBegin;
	}
	return NULL;
}

int main(){

	char s1[256]="The quick brown fox jumps over the lazy dog";
	char s2[256]="fox";

	char *res = strStr(s1,s2);
	if (res)
		printf("%s\n",res);
	else 
		cout<<"FALSE\n";
	strcpy(s1,"");
	strcpy(s2,"");
	
	res=strStr(s1,s2);
	if(res)
		printf("%s\n",res);
	else	
		cout<<"FALSE\n";
}