class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(&prices==NULL) return 0;
        if(prices.size()==0) return 0;
        int max_pro = 0;
        int local_min = prices[0];
        
        for(int i=0;i<prices.size();i++){
            if(local_min>prices[i]) local_min=prices[i];
            
            if((prices[i]-local_min)>max_pro) max_pro = prices[i]-local_min;
        }
        return max_pro;
    }
};
