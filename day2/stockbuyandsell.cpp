class Solution {
public:
    int stockbuySell(vector<int>& arr) {
       
        int minPrice = INT_MAX;


        int maxProfit = 0;

        
        for (int price : arr) {
        
            if (price < minPrice) {
                minPrice = price;
            }

            else {
                maxProfit = max(maxProfit, price - minPrice);
            }
        }

     
        return maxProfit;
    }
};
