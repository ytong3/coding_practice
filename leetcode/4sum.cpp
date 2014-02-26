class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        if (num.size()<4)
            return res;
        
        sort(num.begin(),num.end());
        
        int p1(0),p2,p3,p4(num.size()-1);
        for (p1;p1<=num.size()-4;p1++){
            for (p4=num.size()-1;p4>=p1+3;p4--){
                p2 = p1+1;
                p3 = p4-1;
                int newtarget = target-num[p1]-num[p4];
                
                while (p2<p3)
                {
                    int sum = num[p2]+num[p3];
                    if (sum>newtarget)
                    {
                        while (p3>0&&num[p3]==num[p3-1]) p3--;
                        p3--;
                    }else if (sum<newtarget)
                    {
                        while (p2<num.size()-1&&num[p2]==num[p2+1]) p2++;
                        p2++;
                    }else {
                        vector<int> temp;
                        temp.push_back(num[p1]);
                        temp.push_back(num[p2]);
                        temp.push_back(num[p3]);
                        temp.push_back(num[p4]);
                        res.push_back(temp);
                        while (p2<num.size()-1&&num[p2]==num[p2+1]) p2++;
                        p2++;
                        while (p3>0&&num[p3]==num[p3-1]) p3--;
                        p3--;
                    }
                }
                while (p4>0&&num[p4]==num[p4-1]) p4--;
            }
            while (p1<num.size()-1&&num[p1]==num[p1+1]) p1++;
        }
        return res;
    }
};