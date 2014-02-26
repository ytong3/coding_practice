#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool is_rotation(char* s1, char*s2) {
	if (strlen(s1)!=strlen(s2))
		return false;

	char buf[100];
	
	strcpy(buf,s1);
	strcat(buf,s2);

	char* res=strstr(buf,s2);
	if (res) return true;
	else return false;
}

int main(){
	char s1[]="rotate";
	char s2[]="tatero";
	
	strcpy(s1,"tomato");
	strcpy(s2,"matoto");


	cout<<(is_rotation(s1,s2)?"TRUE":"FALSE")<<endl;
}

