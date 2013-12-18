class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string res="";
        vector<string> res_col;
        helper(digits,0,res,res_col);
        return res_col;
    }
    
    void helper(string &digits, int idx, string &res, vector<string> &res_col){
        if(idx==digits.length()){
            res_col.push_back(res);
            return;
        }
        
        char cur=digits[idx];
        char curLetter;
        if(cur=='9'||cur=='7'){
            for(int i=0;i<4;i++){
                curLetter=(cur=='9'?'w':'p')+i;
                res+=curLetter;
                helper(digits,idx+1,res,res_col);
                res.erase(res.end()-1);
            }
        }else if (cur<'7'){
            for(int i=0;i<3;i++){
                curLetter=(cur-'2')*3+'a'+i;
                res+=curLetter;
                helper(digits,idx+1,res,res_col);
                res.erase(res.end()-1);
            }
        }else{
            for(int i=0;i<3;i++){
                curLetter='t'+i;
                res+=curLetter;
                helper(digits,idx+1,res,res_col);
                res.erase(res.end()-1);
            }
        }
    }
};