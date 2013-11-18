class Solution {
public:
       int minCut(string s) {  
            int len = s.size();
            int D[len+1]; //with a senitle 
            bool P[len][len];  
            //the worst case is cutting by each char
            for(int i=0;i<len;i++)
                for(int j=0;j<len;j++)
                    P[i][j]=false;
            
            for(int i=0;i<len+1;i++){
                D[i]=i-1;
            }
            
            for(int i=0;i<len;i++){
                for(int j=i;j>=0;j--){
                    if(s[i]==s[j]&&((i-j<2)||P[j+1][i-1]==true)){
                        P[j][i]=true;
                        D[i+1]=min(D[i+1],D[j]+1);
                    }
                }
            }
            return D[len];
       }
       
};
