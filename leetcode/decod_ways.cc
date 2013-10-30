 class Solution {  
 public:  
   int numDecodings(string s) {  
     // Note: The Solution object is instantiated only once and is reused by each test case.  
     if(s.length()==0)  
       return 0;  
     if(s[0]=='0')  
       return 0;  
     vector&lt;int&gt; A(s.length(),0);  
     A[0]=1;  
     for(int idx=1;idx&lt;s.length();idx++){  
       A[idx]=A[idx-1];  
       if(s[idx]=='0'){  
         if(s[idx-1]&gt;'0'&amp;&amp;s[idx-1]&lt;'3'){  
           if(idx==1)  
             A[idx]=1;  
           else  
             A[idx]=A[idx-2];  
         }else  
           return 0;  
       }else{  
         if((s[idx-1]=='2'&amp;&amp;s[idx]&lt;'7')||s[idx-1]=='1'){  
           if(idx==1)  
             A[idx]=2;  
           else   
             A[idx]=A[idx-2]+A[idx-1];  
         }  
       }  
     }  
     return A[s.length()-1];  
   };  
 };  
