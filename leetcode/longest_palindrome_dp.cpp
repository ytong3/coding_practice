#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
/*
    string longestPalindrome(string s) {
        int n = s.length();
        int longestBegin = 0;
        int maxLen = 1;
        bool table[1000][1000] = {false};
        for (int i = 0; i < n; i++) {
            table[i][i] = true;
        }
        for (int i = 0; i < n-1; i++) {
            if (s[i] == s[i+1]) {
                table[i][i+1] = true;
                longestBegin = i;
                maxLen = 2;
            }
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n-len+1; i++) {
                int j = i+len-1;
                if (s[i] == s[j] && table[i+1][j-1]) {
                    table[i][j] = true;
                    longestBegin = i;
                    maxLen = len;
                }
            }
        }
        return s.substr(longestBegin, maxLen);
    }
*/
    string longestPalindrome(string s) {
        if (s.length()<=1) return s;
        int maxLen = 1;
        int startIdx=0;

        string longestPal;
        int N = s.length();
        cout<<N<<endl;
        vector<vector<bool> > dp(N,vector<bool>(N,false));
        
        for (int i=0;i<N;i++){
            dp[i][i]=true;
            if(i+1<N&&s[i]==s[i+1]) dp[i][i+1]=true;
        }
        
        for (int i=N-1;i>=0;i--){
            for (int j=N-1;j>i+1;j--){
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    if (j-i+1>maxLen){
                        startIdx = i;
                        maxLen = j-i+1;
                    }
                }
            }
        }
        printTable(dp);
        return s.substr(startIdx,maxLen);
    }
    
void printTable(vector<vector<bool> > &table){
    for(auto &row:table){
        for(auto ele:row)
            cout<<ele<<" ";
        cout<<endl;
        }
    }
};

int main(){
    Solution mySol;
    cout<<mySol.longestPalindrome("aaaaaaaaaaaaaaaaaaaa")<<endl;
    
}

