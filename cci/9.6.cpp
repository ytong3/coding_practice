/*
Given a matrix in which each row and each column is sorted, write a method to find
an element in it.
*/

#include <iostream>
#include <vector>

using namespace std;

//non-reversion version
int find_element(vector<vector<int> > mat, int target){
	int M=mat.size();//nrow
	int N=mat[0].size();//ncol
	
	int row(0),col(N-1);
	
	while(row<M&&col>=0){
		if(col[row][col]==target)
			return true;
			
		if(col[row][col]>target){
			col--;
		else{
			row++;
		}
	}
	return false;
}
	
