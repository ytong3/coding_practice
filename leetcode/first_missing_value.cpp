/*This is a wrong solution. Need to use bucket sort like solution.

#include <iostream>
#include <vector>
#include <climits>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n==0) return 1;
        
        
        int max(0),min(INT_MAX),sum(0);
        for(int idx=0;idx<n;idx++){
            if(A[idx]>0){
            		if(A[idx]>max||A[idx]<min){
            			sum+=A[idx];
            			max=max>A[idx]?max:A[idx];
                		min=min<A[idx]?min:A[idx];
            		}
            	}

        }
        
        if(min!=1)//1 does not appear.
            return 1;
        
        
        
        int residual = (1+max)*max/2-sum;//will only work if the missing value is between greater than 1. 
        
        printf("%d, %d, %d\n",min, max, residual);
        if(residual)
            return residual;
        return max+1;
    }
};

int main(){
	Solution my_sol;
	int vec[1];
	vec[0]=1;
	cout<<my_sol.firstMissingPositive(vec,1);
}
	
	
