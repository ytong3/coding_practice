class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        multimap<int,int> valIdx;
        for(int i=0;i<numbers.size();i++){
            valIdx.insert(make_pair(numbers[i],i+1));
        }
        multimap<int,int>::iterator it1,it2;
        it1=valIdx.begin();
        it2=valIdx.end();
        it2--;//very important as valIdx.end() points to the position next to the last element.
        int sum(0);
        vector<int> res(2,0);
        
        while(it1->first<=it2->first){
            sum=it1->first+it2->first;
            if(sum==target){
                res[0]=it1->second;
                res[1]=it2->second;
                sort(res.begin(),res.end());
                return res;
            }else if (sum>target){
                it2--;
            }else{
                it1++;
            }
        }
        return res;
    }
};