class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.size()==0) return 0;
        vector<int> profit;
        profit.resize(prices.size(),0);
        
        const int length = prices.size();
        int l_min(prices[0]), l_max(0),max_p(0);//BUG here. l_min was initialized as 0;
        int to_return;
        for(int i=1;i<length;i++){
            if(prices[i]<l_min) l_min=prices[i];
            if(prices[i]-l_min>max_p)
                max_p=prices[i]-l_min;
            
            profit[i]=max_p;
        }
        
        max_p=0;
        l_max=prices[length-1];
        to_return = 0;
        for(int i=length-1;i>=0;i--){
            if(l_max<prices[i]) l_max=prices[i];
            max_p=max(max_p,l_max-prices[i]);
 
            
            to_return=max(to_return, max_p+profit[i]);
        }
        
        return to_return;
    }
};
