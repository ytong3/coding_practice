class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(),num.end());
        int len=num.size();
        vector<vector<int> > ret;
        
        for(int i=0;i<len;i++){
            int target = 0-num[i];
            //reducing to a 2 sum problem
            
            int start(i+1),end(len-1);//imposing the accending order in the triplet still covers all the solution
            while(start<end){
                if(num[start]+num[end]==target){
                    vector<int> res;
                    res.push_back(num[i]);
                    res.push_back(num[start]);
                    res.push_back(num[end]);
                    ret.push_back(res);
                    start++;
                    end--;
                    while(start<end&&num[start]==num[start-1])//get start and end ready for the next loop.
                        start++;
                    while(start<end&&num[end]==num[end+1])
                        end--;
                }else if(num[start]+num[end]<target){
                    start++;
                }else{
                    end--;
                }
            }
            if(i<len-1){
                while(num[i]==num[i+1]) i++;//what we need next is i+1 after this. But the for-loop will do i++, so do not do it here.
            }
            
        }
        return ret;
    }
};