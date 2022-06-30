class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), pivot, ans = 0;
        sort(begin(nums), end(nums));
        
        if(n % 2 == 0) // Even number
            pivot = (nums[n / 2 - 1] + nums[n / 2])/2; // average of 2 middle elements
        else           // Odd number
            pivot = nums[n/2];
        
        for(auto i: nums)
            ans += abs(i - pivot); // take the absolute difference from the pivot number
        
        return ans;
    }
};