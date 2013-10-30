#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> res;
        
        if(strs.size()==0)
            return res;
        
        if(strs.size()==1)
            return res;
            
        map<string, vector<string> > hash_table;
        
        for(int idx_strs=0;idx_strs<strs.size();idx_strs++){
            //get the signature;
            string cur_str = strs[idx_strs];
            sort(cur_str.begin(),cur_str.end());
            if(hash_table.find(cur_str)!=hash_table.end())
                hash_table[cur_str].push_back(strs[idx_strs]);
            else
                hash_table.insert(make_pair(cur_str,vector<string>(1, strs[idx_strs])));
        }
        
        map<string, vector<string> >::iterator it;
        for(it=hash_table.begin();it!=hash_table.end();it++){
            if(it->second.size()==1)
                continue;
            for(int idx_strs=0;idx_strs<it->second.size();idx_strs++)
                res.push_back(it->second[idx_strs]);
        }
        return res;
        
    }
};
