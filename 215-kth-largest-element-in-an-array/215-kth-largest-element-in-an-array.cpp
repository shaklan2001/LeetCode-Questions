class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin() , nums.end());
    reverse(nums.begin() , nums.end());
    
    int g=0;
    for(int i=0; i<k; i++)
    {
        g=nums[i];
    }
    return g;

    }
};