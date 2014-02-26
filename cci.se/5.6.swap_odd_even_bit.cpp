#include <iostream>
#include <string>
#include <vector>

using namespace std;

int swap(int x){
	return ((x&0xaaaaaaaa)>>1)|((x&0x55555555)<<1);
}
