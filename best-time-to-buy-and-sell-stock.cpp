class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0 || prices.size() == 1){
            return 0;
        }
        int i = 0;
        int j = 1;
        int maxProfit = 0;
        while(j<prices.size()){
            int profit = prices[j] - prices[i];
            maxProfit = max(maxProfit, profit);
            if(profit<0){
                i = j;
                j++;
            }
            else{
                j++;
            }
        }
        return maxProfit;
    }
};