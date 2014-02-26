#include <iostream>
#include <string>
#include <vector>
using namespace std;

void setZeros(vector<vector<int> > &mat){
	int M = mat.size();
	int N = mat[0].size();
	
	if (M==0||N==0) return;

	bool clearRow = false, clearColumn = false;

	for (int i=0;i<N;i++){
		if (mat[0][i]==0){
			clearRow=true;
			break;
		}
	}

	for (int i=0;i<M;i++){
		if (mat[i][0]==0){
			clearColumn=true;
			break;
		}
	}

	//use the first row and first column as the marker
	for (int row=1;row<M;row++)
		for(int col=1;col<N;col++){
			if (mat[row][col]==0){
				mat[0][col]=0;
				mat[row][0]=0;
			}
		}
	
	for (int i=0;i<N;i++)
		if (mat[0][i]==0){
			for (int j=1;j<M;j++)
				mat[j][i]=0;
			}
	
	for (int i=0;i<M;i++)
		if (mat[i][0]==0){
			for (int j=1;j<N;j++)
				mat[i][j]=0;
			}

	if (clearRow)
		for(int i=0;i<N;i++)
			mat[0][i]=0;
	
	if (clearColumn)
		for(int i=0;i<M;i++)
			mat[i][0]=0;
	
	return;
}
			
int main(){
	vector<vector<int> > mat(9,vector<int>(9,0));

	for(int i=0;i<81;i++){
		mat[i/9][i%9]=i+1;
	}

	mat[7][2]=0;
	mat[3][4]=0;
	mat[8][8]=0;
	
	for (vector<int> row:mat)
	{
		for(int i:row)
			printf("%d\t",i);
		printf("\n");
	}
	setZeros(mat);
	cout<<"======================================"<<endl;
	for (vector<int> row:mat)
	{
		for(int i:row)
			printf("%d\t",i);
		printf("\n");
	}
}
