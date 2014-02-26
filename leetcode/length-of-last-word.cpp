//must consider three situtations
//1. *
//2. *word
//3. *word*
//4. word*

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (strlen(s)==0)
            return 0;
        
        int i = strlen(s)-1;
        //work from backward since it asks the length of the last word
        while(i>=0&&s[i]==' ') i--;
        
        if (i==-1) return 0;
        
        int j = i-1;
        while (j>=0&&s[j]!=' ')
            j--;
        if (j==-1) return i+1;
        return i-j;
        
    }
};