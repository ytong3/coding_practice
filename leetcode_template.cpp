#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <cstdlib>
#include <stack>
#include "linkedlist.h"

typedef LLNode ListNode;

using namespace std;

//Definition for an interval.
  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };


class Solution {
    
    static bool compare(Interval a, Interval b){
        return a.start<b.start;
    }
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        sort(intervals.begin(),intervals.end(),compare);
        vector<Interval> res;
        auto it = intervals.begin();
        while (it!=intervals.end()&&it->end<newInterval.start){
            res.push_back(*it);
            it++;
        }
        
        if (it==intervals.end()) {res.push_back(newInterval);return res;}
        
        //see if it can merge with newInterval
        if (newInterval.end<it->start){
            res.push_back(newInterval);
            while (it!=intervals.end())
                res.push_back(*(it++));
            return res;
        }
        else{
            //merge the two
            it->start = min(it->start,newInterval.start);
            it->end = max(it->end,newInterval.end);
            res.push_back(*it);
        }
        
        //find the a subsequent interval whose start is less than newInterval's end
        auto nit = it+1;
        it = res.end()-1;
        while (nit!=intervals.end()&&nit->end<=it->end){
            nit++;
        }
        
        if (nit!=intervals.end()){
            if(nit->start<=it->end){
                it->end = nit->end;
                ++nit;
            }
            
            while(nit!=intervals.end())
                res.push_back(*(nit++));
            
        }
        return res;
    }
};

int main(){
    vector<Interval> it={Interval(1,2),Interval(3,4),Interval(5,6)};
    Interval newInterval(2,4);
    Solution mysol;
    auto res = mysol.insert(it,newInterval);
    for(auto &e:res){
        cout<<e.start<<","<<e.end<<endl;
    }
    
}
		
