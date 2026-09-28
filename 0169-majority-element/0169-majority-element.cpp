class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0;
        int mid=l+(n-l)/2;
        return nums[mid];
    }
};