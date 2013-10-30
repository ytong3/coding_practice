class Solution {
public:
    vector<string> res;
    vector<string> tempRes;

    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //first break the string into four pieces, which are two-digit or three-digit numbers
        //error cheching
        res.clear();
        tempRes.clear();
        if(s.length()<4||s.length()>12) return res;
        
        partitionIPAddresses(s, 1, 4);
        return res;

        
        
    }
    
    void partitionIPAddresses(string s, int pos, int numParts){
    		//base case
    		if(numParts==1){
    			if(s.length()>0){
    				tempRes.push_back(s);
    				if(isValidIPAddr(tempRes)){
                        string temp=tempRes[0];
                        for(int i=1;i<4;i++){
                            temp=temp+"."+tempRes[i];
                        }
                        res.push_back(temp);			
    				}
    				tempRes.pop_back();
    				}
    		}
    		
    		while(pos<4){
    			if(pos>=s.length()) break;
    			tempRes.push_back(s.substr(0,pos));
    			partitionIPAddresses(s.substr(pos), 1, numParts-1);
    			tempRes.pop_back();
    			pos++;
    			}
    		}
    		
    	bool isValidIPAddr(vector<string> addr){
    		if(addr.size()!=4) return false;
    		
    		int segNum = 0;
    		int intVal = 0;
    		for(segNum=0;segNum<4;segNum++){
                if(addr[segNum][0]=='0'&&addr[segNum].length()>1) return false;
    			intVal=atoi(addr[segNum].c_str());
    			if(intVal>255) return false;
    			}
    		return true;
    	}
};
