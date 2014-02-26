#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

int get_path(int x, int y, int N){
	if (x==N-1&&y==N-1)
		return 1;
	int l = 0, d=0;
	if (x<N-1) l = get_path(x+1,y,N);
	if (y<N-1) d = get_path(x,y+1,N);
	return l+d;
}
		
int get_path_dp(int N, int M) {
	vector<vector<int> > dp(N,vector<int>(M,0));
	for (int i=0;i<N;i++)
		dp[i][M-1]=1;
	for (int i=0;i<M;i++)
		dp[N-1][i]=1;
	
	for (int i=N-2;i>=0;i--)
		for (int j=M-2;j>=0;j--)
			dp[i][j]=dp[i+1][j]+dp[i][j+1];
	
	return dp[0][0];
}

void timer(clock_t start){
	double duration = (clock()-start)/(double)CLOCKS_PER_SEC;
	cout<<"Time elapsed: "<<duration<<endl;
}

int main() {
	clock_t start = clock();
	cout<<"Solved by DP\t"<<get_path_dp(16,16)<<endl;
	
	timer(start);
	start = clock();
	cout<<"Solved by recursion\t"<<get_path(0,0,16)<<endl;
	timer(start);
}
