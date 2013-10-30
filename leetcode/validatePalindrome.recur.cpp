 #include <iostream>
 #include "math.h"
 #include <cstdlib>
 #include <cstdio>
 
 using namespace std;
 bool palindromeHelper(string, int, int);
    
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.length()==0) return true;
        
        return palindromeHelper(s,0,s.length()-1);
        
    }
    
    bool palindromeHelper(string s, int start, int end){
        printf("%d, %d, %c, %c\n", start, end, s[start], s[end]);
        	
        if (start==s.length())
            return true;
        if (end==0)
            return true;
        
        //first make sure both start and end point to a letter
        if (s[start]<'A'||s[start]>'z'||(s[start]>'Z'&&s[start]<'a')){
            return palindromeHelper(s,start+1,end);
        }
        
        if (s[end]<'A'||s[end]>'z'||(s[end]>'Z'&&s[end]<'a')){
            return palindromeHelper(s,start,end-1);
        }
        
        if(start>=end){
            return true;
        }
        if(start+1==end){
            return s[start]==s[end];
        }
        
        if(s[start]==s[end]||abs(s[start]-s[end])=='a'-'A')
            return palindromeHelper(s,start+1,end-1);
        
        return false;
    }
    
int main(){
	cout<<isPalindrome("A man, a plan, a canal: Panama")<<endl;
}
