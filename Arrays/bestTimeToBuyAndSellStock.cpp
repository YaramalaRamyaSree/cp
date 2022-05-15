/*
leetcode link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

    int maxProfit(vector<int>& prices) {
        int maxPro=0;
        int minPrice=INT_MAX;
        for(auto it:prices){
            maxPro=max(maxPro,it-minPrice);
            minPrice=min(minPrice,it);
        }
        return maxPro;
    }
