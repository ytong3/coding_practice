class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size()==0)
            return "";
        if (strs.size()==1)
            return strs[0];
        
        int idx(0);
        while(true)
        {
            for(int i=1;i<strs.size();i++)
            {
                if(idx==strs[i].length())
                    return strs[i];
                if(strs[i][idx]!=strs[i-1][idx])
                    return strs[i].substr(0,idx);
            }
            idx++;
        }
    }
};