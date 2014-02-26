#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <assert.h>
using namespace std;

void rotate_matrix(vector<vector<int> > &mat){
	assert(mat.size()==mat[0].size());
	int N=mat.size();
	for (int layer=0;layer<N/2;++layer) {
		int first = layer;
		int last = N-1-layer;
		//note that it should be i<last instead of i<=last
		//as last will directly be used in the for-loop body.
		//the four edges on the same 'layer' does not make a exact rectangle.
		//it is like
		/*
			aaaaab
			d	 b
			d	 b
			d	 b
			d	 b
			dccccc
		*/
		for (int i=first;i<last;++i) {
			int offset = i-first;
			int top = mat[first][i];
			
			//left->top
			mat[first][i]=mat[last-offset][first];
			//bottom->left
			mat[last-offset][first]=mat[last][last-offset];
			//right->bottom
			mat[last][last-offset]=mat[i][last];
			//top->right;
			mat[i][last]=top;
		}
	}
}

int main(){
	vector<vector<int> > mat(8,vector<int>(8,0));

	for(int i=0;i<64;++i)
		mat[i/8][i%8]=i+1;
	
	rotate_matrix(mat);

	for(int i=0;i<8;++i){
		for(int j: mat[i]) cout<<j<<" ";
		cout<<endl;
	}
}