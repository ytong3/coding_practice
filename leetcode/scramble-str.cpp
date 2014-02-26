class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1==s2)
            return true;
        
        int split1, split2;
        
        for (int split1=1;split1<=s1.length()-1;split1++)
        {
            split2=split1;
            int len1(s1.length()),len2(s2.length());
            string s11 = s1.substr(0,split1);
            string s21 = s2.substr(0,split2);
            string s12 = s1.substr(split1,len1-split1);
            string s22 = s2.substr(split2,len2-split2);
            if (isAnagram(s11,s21)&&
                isScramble(s11,s21)&&
                isAnagram(s12,s22)&&
                isScramble(s12,s22))
                return true;
            else
            {
                split2=len2-split1;
                string s11 = s1.substr(0,split1);
                string s21 = s2.substr(0,split2);
                string s12 = s1.substr(split1,len1-split1);
                string s22 = s2.substr(split2,len2-split2);
                if (isAnagram(s11,s22)&&
                    isScramble(s11,s22)&&
                    isAnagram(s12,s21)&&
                    isScramble(s12,s21))
                    return true;
            }
        }
        return false;
    }
    
    bool isAnagram(string s1, string s2){
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return s1==s2;
    }
};