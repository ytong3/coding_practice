class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen(0);
        bool check[256]={false};
        
        int i(0),j(0);
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
        maxLen=max(maxLen,(int)s.length()-i);
        return maxLen;
    }
};