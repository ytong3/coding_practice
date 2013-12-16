class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen(0);
        bool check[256]={false};
        
        int i(0),j(0);//considering the substring between i(inclusive) and j(exclusive)
        while(j<s.length()){
            if(check[s[j]]){
                maxLen=max(maxLen,j-i);
                while(s[i]!=s[j]){
                    check[s[i]]=false;
                    i++;
                }
                i++;
                j++;
            }else{
                check[s[j]]=true;
                j++;
            }
        }
        
        maxLen=max(maxlen,n-i);//j takes value up to n-1, and substring [i,j) does not include char at j, so the last char is not considered without adding this line.
        
        return maxLen;
    }
};