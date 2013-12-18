class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int strLen=s.length();
        bool dp[s.length()+1];
        for(int i=0;i<strLen+1;i++)
            dp[i]=false;
        
        dp[0]=true;
        for(int i=1;i<strLen+1;i++){//i is the length of the substr [0,i)
            for(int j=i-1;j>=0;j--){//j is index of the last char in the substr. dp[j] conrresponds to [0,j)
                if(dp[j]&&dict.find(s.substr(j,i-j))!=dict.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[strLen];
    }
};