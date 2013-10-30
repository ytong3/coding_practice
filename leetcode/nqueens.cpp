#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        vector<vector<string> > res;
        if(n==1){
            vector<string> tmp(1,"Q");
            res.push_back(tmp);
            return res;
        }
        if(n<4)
            return res;
        
        vector<int> used_col(n,0);
        vector<string> solution;
        
        
        recur_helper(n, 0, used_col, solution, res);
        return res;
    }
    
    void recur_helper(int n, int n_queen, vector<int> &used_col, vector<string> &solution, vector<vector<string> > &ans_coll){
        if(n_queen==n){
            ans_coll.push_back(solution);
            return;
        }
        
        for(int col=0;col<n;col++){
            if(used_col[col]==0){
                //check if it can attack the queens that are previously placed;
                int row=0;
                for(;row<n_queen;row++){
                    //if it is in the same diagonal with any previous queen.
                    if(abs(row-n_queen)==abs((int)solution[row].find('Q')-col))
                        break;
                }
                
                if(row!=n_queen)
                    continue;
                //occupy the column
                used_col[col]=1;
                //construct the string
                string tmp = string(n-1,'.');
                tmp.insert(col,"Q");
                solution.push_back(tmp);
                recur_helper(n,n_queen+1,used_col, solution, ans_coll);
                solution.pop_back();
                used_col[col]=0;
            }
        }
    }
};

int main(){
	Solution mysol;
	
	vector<vector<string> > res=mysol.solveNQueens(4);
	
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<endl;
		cout<<endl;
	}
}
		
