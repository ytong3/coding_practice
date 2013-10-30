/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        
        if(n==0||k==0)
            return res;
        
        return recur_helper(n, k);
    }
    
    vector<vector<int> > recur_helper(int n, int k){
        //base cases
        vector<vector<int> > res;
        
        if(n<k){
            return res;
        }
        
        if(n==k){
            vector<int> tmp_comb;
            for(int i=n;i>0;i--){
                tmp_comb.push_back(i);
            }
            res.push_back(tmp_comb);
            return res;
        }
        
        if (k==1){
           
            int max_n=n;
            
            while(max_n>0){
                vector<int> tmp_comb(1,max_n);
                res.push_back(tmp_comb);
                max_n--;
            }
            
            return res;
        }
        
        //include n
        vector<vector<int> > subres1 = recur_helper(n-1,k-1);
        for(int idx=0;idx<subres1.size();idx++){
            subres1[idx].push_back(n);
        }
        
        //exclude n
        vector<vector<int> > subres2 = recur_helper(n-1,k);
        
        //merge subres1 and subres2
        res = subres1;
        for(int idx=0;idx<subres2.size();idx++){
            res.push_back(subres2[idx]);
        }
        return res;
    }
};

int main(){
	Solution mysol;
	vector<vector<int> > sol = mysol.combine(4,2);
	
	for(int i=0;i<sol.size();i++){
		for(int j=0;j<sol[i].size();j++)
			cout<<sol[i][j];
		cout<<endl;
	}
	
}
