#include <iostream>
#include <cstdlib>

void reverse_str(char *str) {
	int i=0,j=strlen(str)-1;
	while(i<j) {
		char temp = str[i];
		str[i]=str[j];
		str[j]=temp;
		i++;
		j--;
	}
}

int main() {
	char s="Hello, world!";
	printf("%s\n",s);
	reverse_str(s);
	printf("%s\n",s);
}