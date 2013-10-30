//avoid using an primitive array if you can use vector
#include <iostream>
#include <vector>
using namespace std;

void paint_fill(int a[3][6], int width, int height, int i, int j, int old_color, int new_color){
	
	if(a[i][j]==new_color)//leave the cell alone if it is already set to new color
		return;

	if(a[i][j]!=old_color)
		return;
	
	a[i][j]=new_color;
	
	//top
	if(i>0){
		paint_fill(a, width, height, i-1,j, old_color, new_color);
	}
    //bottom
	if(i<height-1){
		paint_fill(a, width, height,i+1,j, old_color, new_color);
	}
	//left
	if(j>0){
		paint_fill(a, width, height,i, j-1, old_color, new_color);
	}
	//right
	if(j<width-1){
		paint_fill(a, width, height,i, j+1, old_color, new_color);
	}
}

int main(){
	int a[3][6]={{1,1,0,0,0,1},{1,0,0,0,0,1},{1,1,1,0,1,1}};
	//int parray[3][6]=a;
	
	for(int idx=0;idx<3;idx++){
		for(int idx1=0;idx1<6;idx1++){
			cout<<a[idx][idx1];
		}
		cout<<endl;
	}
	cout<<"**********"<<endl;
	paint_fill(a,6,3,0,2,a[0][2],2);

	for(int idx=0;idx<3;idx++){
		for(int idx1=0;idx1<6;idx1++){
			cout<<a[idx][idx1];
		}
		cout<<endl;
	}
}
		
