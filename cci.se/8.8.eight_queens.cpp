#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

void eight_queens_print(int index, vector<bool> visited, vector<string > &board,int &count){
	if (index==8) {
		for(string temp:board) {
				cout<<temp<<endl;
		}
		cout<<"*************"<<endl;
		count++;
		return;
	}

	for (int i=0;i<8;i++){
		if (visited[i]==true)
			continue;
		
		//check if the current location is valid

		
		int j;
		for (j=0;j<index;j++){
			int location = board[j].find('O');
			if (abs(j-index)==abs(location-i))
				break;
		}

		if (j!=index)
			continue;
			
		
		visited[i]=true;
		string row(8,'.');
		row[i]='O';
		board.push_back(row);
		eight_queens_print(index+1,visited,board,count);
		board.pop_back();
		visited[i]=false;
	}
}

int main(){
	vector<bool> visited(8,false);
	vector<string > board;
	int count=0;
	eight_queens_print(0,visited,board,count);
	cout<<"Total count: "<<count<<endl;
}

