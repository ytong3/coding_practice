#include <iostream>
#include <string>
using namespace std;

//this problem resembles the problem to merge two array given that the first array is sufficiently large to hold the two arrays. Working from the back is the way to go, as the writing cursor will never run over the read cursor.
void replace_spaces(char *s) {
	//figure out the length of the new string
	int len=strlen(s);
	cout<<len<<endl;
	char *p=s;

	while (*p) {
		if (*p==' ')
			len+=2;
		p++;
	}
	cout<<len<<endl;
	cout<<strlen(s)<<endl;

	int rc(strlen(s)-1);
	s[len]='\0';	
	s[len+1]='\0';
	int wc=len-1;
	for (;rc>=0;rc--){
		if (s[rc]==' ') {
			s[wc--]='0';
			s[wc--]='2';
			s[wc--]='%';
		}else
			s[wc--]=s[rc];
	}
	s[len]='\0';
}

int main(){
	char s[200]="the quick brown fox jumps over the lazy dog";
	printf("Hello\n");
	printf("Original: %s\n",s);
	replace_spaces(s);
	printf("%s\n",s);
}