class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int bb=prices[0];
        int maxProfit=INT_MIN;
        for (int i=1;i<prices.size();i++){
            if (prices[i]>bb){
                maxProfit=max(maxProfit,prices[i]-bb);
            }
            bb=min(bb,prices[i]);
        }
        if (maxProfit<0) return 0;
        else return maxProfit;
    }
};