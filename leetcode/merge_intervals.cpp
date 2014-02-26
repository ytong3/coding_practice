#include <iostream>
#include <vector>

using namespace std;

struct Interval {
         int start;
         int end;
         Interval() : start(0), end(0) {}
         Interval(int s, int e) : start(s), end(e) {}
};



class Solution {
public:
    
    static bool mycompare(Interval a, Interval b){
        return a.start<b.start;
    }
    
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size()==0) return intervals;
        sort(intervals.begin(),intervals.end(),mycompare);
        vector<Interval> ret;
        ret.push_back(intervals[0]);
        auto it = intervals.begin();
        it++;
        while (it!=intervals.end()) {
            Interval &temp = ret.back();
            if (it->start==temp.start){
                temp.end = max(temp.end,it->end);
            }else if (it->start<ret.back().end)
                ret.back().end = max(ret.back().end,it->end);
            else
                ret.push_back(*it);
            it++;
        }
        return ret;
    }
    
    
};

int main(){
    Solution mysol;
    vector<Interval> input;
    input.push_back(Interval(1,4));
    input.push_back(Interval(1,4));
    //input.push_back(Interval(8,10));
    //input.push_back(Interval(15,18));

    auto res =mysol.merge(input);
    for (auto ele:res){
        cout<<ele.start<<","<<ele.end<<endl;
    }
    
}