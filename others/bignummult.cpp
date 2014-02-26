#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::endl;

void bigNumMult(vector<int> a, vector<int> b, vector<int> &res){
	int index(0);	
	while (index<b.size()){	
		int num = b[index];
		vector<int> temp_res(a.size()+1,0);
		for (int i=0;i<a.size();i++){
			int temp_val = num*a[i]+temp_res[i];
			temp_res[i]=temp_val%10;
			temp_res[i+1]+=temp_val/10;
		}

		int j=index;
		for (int i=0;i<temp_res.size();i++){
			int temp_val = res[j]+temp_res[i];
			res[j] = temp_val%10;
			res[j+1]+=temp_val/10;
			j++;
		}	
	index++;
	}
}

void printNum(vector<int> n){
	vector<int>::reverse_iterator rit = n.rbegin();
	while(rit!=n.rend()){
		cout<<*rit;
		rit++;
	}
}

int main(){
	int a[] = {1,3,4,2,3,2,5,4,5,4,3,4,5,4,3,2,3,4,3,2,3,4,5,6,7};
	//a[]={6,5,4,3,2,1};
	vector<int> num(a,a+25);
	vector<int> res(2*num.size()+1,0);
	
	bigNumMult(num,num,res);
	
	cout<<"Big num multiplication"<<endl;
	printNum(num);
	cout<<"*";
	printNum(num);
	cout<<" equals"<<endl;
	printNum(res);
	cout<<endl;
}
	

	
	
	


