#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool compare_by_height(pair<int,int> p1, pair<int,int> p2){
	return p1.first<p2.first;
}

bool compare_by_weight(pair<int,int> p1, pair<int,int> p2){
	return p1.second<p2.second;
}

void sort_by(vector<pair<int,int> > &cast, int by=0){
	if (by==0) sort(cast.begin(),cast.end(),compare_by_height);
	else sort(cast.begin(),cast.end(),compare_by_weight);
}

vector<pair<int,int> > find_longest_tower(vector<pair<int,int> > &cast){
	sort_by(cast);
	for(pair<int,int> d:cast)
		cout<<d.first<<","<<d.second<<endl;
	cout<<"*******************"<<endl;	
	int start(0), end(0), maxStart, maxEnd, maxLen(0);
	for (int i=1;i<=cast.size();i++){
		if (i==cast.size()||cast[i].second<cast[i-1].second){
			//compare with current max;
			end = i-1;
			if (end-start+1>maxLen){
				maxLen = end-start+1;
				maxStart = start;
				maxEnd = end;
			}
			start=i;
		}
	}		
	
	

	return vector<pair<int,int> >(cast.begin()+maxStart,cast.begin()+maxEnd+1);
}
		
int main(){
	vector<pair<int,int> > cast;
	cast.push_back(make_pair(60,89));
	cast.push_back(make_pair(70,150));
	cast.push_back(make_pair(56,50));
	cast.push_back(make_pair(75,190));
	cast.push_back(make_pair(60,151));
	cast.push_back(make_pair(68,110));
	
	vector<pair<int,int> > res = find_longest_tower(cast);
	for (pair<int,int> u:res)
		cout<<u.first<<","<<u.second<<endl;
}
