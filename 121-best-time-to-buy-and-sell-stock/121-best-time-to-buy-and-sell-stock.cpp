class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<1)
            return 0;
        int maximum = prices[n-1];
        int ans=0;
        for(int i=n-1;i>=0;i--){
            maximum=max(maximum,prices[i]);
            int curSum = maximum-prices[i];
         ans = max(ans,curSum);   
        }
        return ans;
    }
};