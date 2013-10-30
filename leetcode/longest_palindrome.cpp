//Given a string S, find the longest palindromic substring in S.
//Can also be solved with DP with a big table. http://leetcode.com/2011/11/longest-palindromic-substring-part-i.html

#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.length()==1)
            return s;
        
        
        string longest_palindrome("");
        //brute force
        for(int idx1=0;idx1<s.length();idx1++){
            for(int idx2=s.length()-1;idx2>idx1;idx2--){
                if(idx2-idx1+1<longest_palindrome.length())
                    break;
                
                if(s[idx1]==s[idx2]){
                    int p1(idx1),p2(idx2);
                    while(s[p1]==s[p2]&&p1<p2){
                        p1++;
                        p2--;
                    }
                    
                    if(p1>=p2){
                        if(idx2-idx1+1>longest_palindrome.length())
                            longest_palindrome = s.substr(idx1,idx2-idx1+1);
                    }else{   
                        continue;
                    }
                }
            }
        }
        return longest_palindrome;
 }
 
 int main(){
 	cout<<longestPalindrome("aaabaaaa")<<endl;
 }
