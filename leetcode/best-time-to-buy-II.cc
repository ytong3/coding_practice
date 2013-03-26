class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max_pro=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]) max_pro+=(prices[i]-prices[i-1]);
        }
        return max_pro;
    }
};
