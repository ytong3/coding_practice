class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        if(candidate.size()==0)
            return ans;
            
        sort(candidates.begin(),candidates.end());
        
        return helper(candidates,target,candidates.size()-1);
    }
    
    vector<vector<int> > helper(vector<int> &sorted_candidates, int target, int idx){
        vector<vector<int> > ans;//empty answer
        
        
        if(idx<0)
            return ans;
        
        if(idx==0){
            if(target%sorted_candidates[idx]==0){
                int num=target/sorted_candidate[idx];
                vector<int> comb(num, sorted_candidates[idx]);
                ans.push_back(comb);
            }
            return ans;
        }
        
        int maxNum = target/sorted_candidates[idx];
        for(int numOfCan=maxNum;numofCan>=0;numOfCan--){
            vector<vector<int> > subRes=helper(sorted_candidates, target-numOfCan*sorted_candidates[idx], idx-1);
            for(int subResIdx=0;subResIdx<sbuRes.size();comIdx++){
                vector<int> temp = subRes[subResIdx];
                for(int tmpCounter=numOfCan;tmpCounter>0;tmpCounter--){
                    temp.push_back(sorted_candidates[idx]);
                }
                ans.push_back(temp);
            }
                
        }
        
        return ans;
    }
};
