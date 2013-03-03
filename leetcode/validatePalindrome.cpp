class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!s.size()) return true;
        int head(0), tail(s.size()-1);
        while(head<tail){
            while(head<tail&&!isLetter(s[head])&&!isDigit(s[head])) head++;
            while(head<tail&&!isLetter(s[tail])&&!isDigit(s[tail])) tail--;
            if(head>=tail) break;
            if(!isSameLetter(s[head],s[tail])) return false;
            head++;
            tail--;
        }
        return true;
    }
    bool isSameLetter(char a, char b){
        if(a>='a') a=a+('A'-'a');
        if(b>='a') b=b+('A'-'a');
        if(a==b) return true;
        return false;
    }
    bool isLetter(char a){
        if(a<'A') return false;
        if(a>'Z'&&a<'a') return false;
        if(a>'z') return false;
        return true;
    }
    bool isDigit(char a){
        if(a<'0') return false;
        if(a>'9') return false;
        return true;
    }
};
