class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        //fill from the back in A
        int len=m+n;
        int iA(m-1),iB(n-1),i(len-1);
        while(iA>=0&&iB>=0){
            if(A[iA]>B[iB]){
                A[i]=A[iA];
                iA--;
            }
            else{
                A[i]=B[iB];
                iB--;
            }
            i--;
        }
        if(iB<0)
            return;
        if(iA<0)
            while(iB>=0){
                A[i]=B[iB];
                i--;
                iB--;
            }
        return;
        
    }
};
/*
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
*/
