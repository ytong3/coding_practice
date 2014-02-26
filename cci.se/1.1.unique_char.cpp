#include <iostream>
#include <string>
using namespace std;
bool check_unique_char(const char *str) {
	int existed[256]={0};
	const char *p = str;
	while (*p){
		if (existed[*p]==1)
			return false;
		else
			existed[*p]=1;
		p++;
	}

	return true;
}

//if a hashmap need to be used but extra data structure is not allowed. Consider bitmaps.
bool check_unique_char_bitmap(char *str) {
	int bitmap=0;//this is a 32 bit int.
	char *p=str;
	while (*p){
		int pos = *p-'a';
		if (bitmap&(1<<pos))
			return false;
		bitmap=bitmap|(1<<pos);
		p++;
	}
	return true;
}

int main() {
	char s[]="hello, world";
	char s1[]="Lets go";

	cout<<check_unique_char_bitmap(s)<<endl;
	cout<<check_unique_char(s)<<endl;
	cout<<check_unique_char_bitmap(s1)<<endl;
	cout<<check_unique_char(s1)<<endl;
}