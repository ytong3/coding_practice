class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	if(B==NULL) return;
        if(n==0) return;
        if(A==NULL) return;
        if(m==0){
            for(int i=0;i<n;i++){
                A[i]=B[i];
            }
        }
		
        int tailA(m), idxA(0), tailB(n), idxB(0);
        if(B[idxB]<=A[idxA]){
        		idxB;
        		int count(1);
        		while(B[idxB+count]<=A[idxA]){
        			count++;
        			}
        		tailA=shiftbyn(A,idxA,tailA,count);
        		//fill B to A
        		for(;count>0;count--){
        			A[idxA]=B[idxB];
        			idxA++;
        			idxB++;
        			}
        		}
		while(idxB<tailB){
			while(!(A[idxA]<B[idxB]&&A[idxA+1]>B[idxB])){
				int count(1);
				while(B[idxB+count]<A[idxA+1])
					count++;
				tailA=shiftbyn(A,idxA,tailA,count);
				//fill B to A
				for(;count>0;count--){
					A[idxA]=B[idxB];
					idxA++;
					idxB++;
					}
				}
			}   
    }
    int shiftbyn(int array[],int pos, int tail, int n){
    		for(int idx=tail;idx>=pos;idx++)
    			array[idx+n]=array[idx];
    		return tail+n;
    }
};
