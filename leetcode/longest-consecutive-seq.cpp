class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int maxLen(0);
        map<int,int> table;
        for (int i=0;i<num.size();i++)
        {
            int len=1;
            table.insert(make_pair(num[i],len));
            int lower(num[i]),upper(num[i]);
            if (table.find(num[i]-1)!=table.end())
            {
                int left = num[i]-1;
                lower = left-table[left]+1;
                table[lower]+=1;
                len = table[lower];
                table[num[i]]=len;
            }
            
            if (table.find(num[i]+1)!=table.end())
            {
                int right=num[i]+1;
                upper=right+table[right]-1;
                table[upper]+=table[num[i]];
                table[lower]=table[upper];
                len = table[lower];
                table[num[i]]=len;
            }
            maxLen=max(maxLen,len);
        }
        return maxLen;
    }
};